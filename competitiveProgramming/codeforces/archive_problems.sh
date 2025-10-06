#!/bin/bash

# Archive competitive programming problems into contest directories
# Usage: ./archive_cp_problems.sh [directory]
# If no directory is provided, uses current directory

TARGET_DIR="${1:-.}"

cd "$TARGET_DIR" || exit 1

# Function to extract contest name from file
get_contest_name() {
    local file="$1"
    # Look for "Contest: " line in the header
    local contest=$(grep -m 1 "^\s*\*\s*Contest:" "$file" | sed 's/^\s*\*\s*Contest:\s*//' | sed 's/\s*$//')
    
    if [ -z "$contest" ]; then
        echo ""
        return
    fi
    
    # Clean up contest name: remove "Codeforces " prefix and sanitize
    contest=$(echo "$contest" | sed 's/^Codeforces\s*//')
    # Replace spaces with underscores and remove special characters
    contest=$(echo "$contest" | sed 's/\s\+/_/g' | sed 's/[^a-zA-Z0-9_-]//g')
    
    echo "$contest"
}

# Function to move file with duplicate handling
move_with_duplicate_handling() {
    local src="$1"
    local dest_dir="$2"
    local filename=$(basename "$src")
    local name="${filename%.*}"
    local ext="${filename##*.}"
    
    # If extension is same as name, there's no extension
    if [ "$name" = "$ext" ]; then
        ext=""
    fi
    
    local dest="$dest_dir/$filename"
    local new_name="$name"
    local counter=1
    
    # Check for conflicts and append (1), (2), etc.
    while [ -e "$dest" ]; do
        new_name="${name}_(${counter})"
        if [ -n "$ext" ]; then
            dest="$dest_dir/${new_name}.${ext}"
        else
            dest="$dest_dir/${new_name}"
        fi
        ((counter++))
    done
    
    mv "$src" "$dest"
    echo "  Moved: $filename -> $dest_dir/$(basename "$dest")" >&2
    
    # Return the new base name (without extension) for test file renaming
    echo "$new_name"
}

# Function to move tests directory for a problem
move_tests_directory() {
    local problem_file="$1"
    local dest_dir="$2"
    local new_base_name="$3"  # New base name if file was renamed due to duplicate
    local filename=$(basename "$problem_file")
    local name="${filename%.*}"
    
    # Check if any test files exist for this problem
    local test_files=(tests/${name}_input*.txt tests/${name}_output*.txt)
    local found_tests=false
    
    for test_file in "${test_files[@]}"; do
        if [ -f "$test_file" ]; then
            found_tests=true
            break
        fi
    done
    
    if [ "$found_tests" = true ]; then
        # Create tests directory in destination if it doesn't exist
        mkdir -p "$dest_dir/tests"
        
        # Move all input and output test files
        for test_file in tests/${name}_input*.txt tests/${name}_output*.txt; do
            if [ -f "$test_file" ]; then
                local test_basename=$(basename "$test_file")
                
                # If the problem file was renamed, rename test files too
                if [ "$name" != "$new_base_name" ]; then
                    # Replace old name with new name in test filename
                    local new_test_basename="${test_basename/$name/$new_base_name}"
                    local dest_test="$dest_dir/tests/$new_test_basename"
                else
                    local dest_test="$dest_dir/tests/$test_basename"
                fi
                
                if [ -e "$dest_test" ]; then
                    echo "  Warning: Test file $(basename "$dest_test") already exists in $dest_dir/tests/, skipping"
                else
                    mv "$test_file" "$dest_test"
                    echo "  Moved test: $test_file -> $dest_test"
                fi
            fi
        done
    fi
}

# Process all .cpp, .py, and .c files in current directory (not in subdirectories)
file_count=0
moved_count=0
skipped_count=0

shopt -s nullglob
for file in *.cpp *.py *.c; do
    # Skip if it's a directory
    [ -f "$file" ] || continue
    
    ((file_count++))
    
    contest=$(get_contest_name "$file")
    
    if [ -z "$contest" ]; then
        echo "Skipping $file: No contest header found"
        ((skipped_count++))
        continue
    fi
    
    # Create contest directory if it doesn't exist
    contest_dir="archive/$contest"
    if [ ! -d "$contest_dir" ]; then
        mkdir -p "$contest_dir"
        echo "Created directory: $contest_dir/"
    fi
    
    # Move file with duplicate handling and get new base name
    new_base_name=$(move_with_duplicate_handling "$file" "$contest_dir")
    
    # Move tests directory with the new base name
    move_tests_directory "$file" "$contest_dir" "$new_base_name"
    
    ((moved_count++))
done
shopt -u nullglob

# Clean up binary files (executable files without extensions)
echo ""
echo "Cleaning up binary files..."
binary_count=0

shopt -s nullglob
for file in *; do
    # Skip if it's a directory or this script itself
    [ -f "$file" ] || continue
    [ "$file" = "$(basename "$0")" ] && continue
    
    # Check if file is executable and has no extension
    if [ -x "$file" ] && [[ ! "$file" =~ \. ]]; then
        echo "  Deleting binary: $file"
        rm "$file"
        ((binary_count++))
    fi
done
shopt -u nullglob

echo ""
echo "========================================="
echo "Archive Summary:"
echo "  Total files found: $file_count"
echo "  Files moved: $moved_count"
echo "  Files skipped: $skipped_count"
echo "  Binaries deleted: $binary_count"
echo "========================================="
