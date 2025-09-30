#!/usr/bin/env python3
"""
Enhanced Codeforces Username Availability Checker

This script checks for available "good" usernames on Codeforces using their API.
Features:
- Built-in word dictionary
- Online dictionary API integration
- Thesaurus/synonym lookup
- Real-time status updates
- Multiple output formats
- Result viewing
"""

import requests
import time
import json
import csv
from typing import List, Dict, Set, Optional
import re
from collections import defaultdict
from datetime import datetime

class CodeforcesUsernameChecker:
    def __init__(self):
        self.api_base = "https://codeforces.com/api/user.info"
        self.rate_limit_delay = 2.1  # Slightly over 2 seconds to be safe
        self.session = requests.Session()
        self.session.headers.update({
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
        })
        
        # For online dictionary APIs
        self.dictionary_apis = {
            'free_dictionary': 'https://api.dictionaryapi.dev/api/v2/entries/en/',
            'datamuse': 'https://api.datamuse.com/words'
        }
        
    def get_dictionary_words(self) -> Dict[str, List[str]]:
        """
        Returns categorized dictionary words that make good usernames.
        You can expand this list or load from a file.
        """
        word_categories = {
            'colors': [
                'red', 'blue', 'green', 'yellow', 'purple', 'orange', 'pink', 'brown',
                'black', 'white', 'gray', 'grey', 'cyan', 'magenta', 'lime', 'navy',
                'teal', 'silver', 'gold', 'maroon', 'olive', 'aqua', 'fuchsia',
                'crimson', 'azure', 'beige', 'coral', 'indigo', 'ivory', 'khaki',
                'lavender', 'salmon', 'tan', 'turquoise', 'violet', 'amber', 'jade'
            ],
            'animals': [
                'cat', 'dog', 'lion', 'tiger', 'bear', 'wolf', 'fox', 'eagle',
                'hawk', 'owl', 'shark', 'whale', 'dolphin', 'penguin', 'panda',
                'koala', 'zebra', 'giraffe', 'elephant', 'rhino', 'hippo',
                'leopard', 'cheetah', 'jaguar', 'panther', 'lynx', 'falcon',
                'raven', 'crow', 'swan', 'duck', 'goose', 'rabbit', 'deer',
                'moose', 'elk', 'bison', 'buffalo', 'horse', 'unicorn', 'dragon'
            ],
            'objects': [
                'sword', 'shield', 'crown', 'diamond', 'crystal', 'stone', 'rock',
                'star', 'moon', 'sun', 'fire', 'ice', 'water', 'wind', 'earth',
                'thunder', 'lightning', 'storm', 'cloud', 'rain', 'snow', 'frost',
                'flame', 'spark', 'bolt', 'arrow', 'blade', 'hammer', 'axe',
                'spear', 'bow', 'staff', 'wand', 'orb', 'gem', 'pearl', 'ruby',
                'emerald', 'sapphire', 'topaz', 'garnet', 'opal', 'quartz'
            ],
            'adjectives': [
                'swift', 'quick', 'fast', 'slow', 'calm', 'wild', 'brave', 'bold',
                'wise', 'smart', 'clever', 'bright', 'dark', 'light', 'heavy',
                'strong', 'mighty', 'fierce', 'gentle', 'kind', 'noble', 'royal',
                'ancient', 'modern', 'classic', 'epic', 'legendary', 'mystic',
                'magic', 'divine', 'cosmic', 'stellar', 'lunar', 'solar',
                'frozen', 'burning', 'blazing', 'shining', 'glowing', 'radiant'
            ],
            'nature': [
                'forest', 'mountain', 'river', 'ocean', 'sea', 'lake', 'valley',
                'hill', 'peak', 'cliff', 'cave', 'desert', 'jungle', 'meadow',
                'field', 'garden', 'tree', 'oak', 'pine', 'maple', 'willow',
                'cedar', 'birch', 'ash', 'elm', 'rose', 'lily', 'daisy', 'tulip',
                'orchid', 'jasmine', 'lavender', 'sage', 'mint', 'basil', 'thyme'
            ]
        }
        return word_categories
    
    def get_synonyms_datamuse(self, word: str, max_results: int = 20) -> List[str]:
        """Get synonyms using Datamuse API."""
        try:
            print(f"🔍 Looking up synonyms for '{word}'...")
            url = f"{self.dictionary_apis['datamuse']}?rel_syn={word}&max={max_results}"
            response = requests.get(url, timeout=10)
            
            if response.status_code == 200:
                data = response.json()
                synonyms = [item['word'] for item in data if 'word' in item]
                print(f"  ✅ Found {len(synonyms)} synonyms")
                return synonyms
            else:
                print(f"  ❌ API error: {response.status_code}")
                return []
        except Exception as e:
            print(f"  ❌ Error fetching synonyms: {e}")
            return []
    
    def get_related_words_datamuse(self, word: str, relation_types: List[str] = None, max_results: int = 20) -> Dict[str, List[str]]:
        """
        Get related words using Datamuse API with different relation types.
        
        Relation types:
        - rel_syn: synonyms
        - rel_ant: antonyms  
        - rel_hyp: hyponyms (more specific terms)
        - rel_hyper: hypernyms (more general terms)
        - rel_part: part of
        - rel_whole: whole of
        - rel_rhyme: rhymes with
        - rel_nry: near rhymes
        """
        if relation_types is None:
            relation_types = ['rel_syn', 'rel_hyp', 'rel_hyper']
        
        all_related = {}
        
        for rel_type in relation_types:
            try:
                print(f"🔍 Looking up {rel_type.replace('rel_', '')} for '{word}'...")
                url = f"{self.dictionary_apis['datamuse']}?{rel_type}={word}&max={max_results}"
                response = requests.get(url, timeout=10)
                
                if response.status_code == 200:
                    data = response.json()
                    words = [item['word'] for item in data if 'word' in item]
                    all_related[rel_type] = words
                    print(f"  ✅ Found {len(words)} {rel_type.replace('rel_', '')} words")
                else:
                    print(f"  ❌ API error for {rel_type}: {response.status_code}")
                    all_related[rel_type] = []
                
                time.sleep(0.5)  # Small delay between API calls
                
            except Exception as e:
                print(f"  ❌ Error fetching {rel_type}: {e}")
                all_related[rel_type] = []
        
        return all_related
    
    def get_dictionary_definition(self, word: str) -> Optional[Dict]:
        """Get word definition using Free Dictionary API."""
        try:
            print(f"📚 Looking up definition for '{word}'...")
            url = f"{self.dictionary_apis['free_dictionary']}{word}"
            response = requests.get(url, timeout=10)
            
            if response.status_code == 200:
                data = response.json()
                if data:
                    print(f"  ✅ Found definition")
                    return data[0]  # Return first definition
            else:
                print(f"  ❌ Definition not found")
                return None
        except Exception as e:
            print(f"  ❌ Error fetching definition: {e}")
            return None
    
    def is_good_username(self, username: str) -> bool:
        """Check if a username meets our 'good' criteria."""
        if not username:
            return False
        
        # Only alphabetic characters
        if not username.isalpha():
            return False
        
        # Reasonable length (3-15 characters)
        if len(username) < 3 or len(username) > 15:
            return False
        
        return True
    
    def check_username_availability(self, username: str) -> Dict[str, any]:
        """
        Check if a username is available on Codeforces.
        Note: We check using lowercase since usernames are case-insensitive,
        but return the original case for display purposes.
        """
        # Use lowercase for the actual API check since usernames are case-insensitive
        username_to_check = username.lower()
        
        try:
            url = f"{self.api_base}?handles={username_to_check}"
            response = self.session.get(url, timeout=10)
            
            # Rate limiting
            time.sleep(self.rate_limit_delay)
            
            if response.status_code == 200:
                data = response.json()
                if data.get('status') == 'OK':
                    # User exists
                    return {
                        'username': username,  # Return original case for display
                        'checked_as': username_to_check,  # Show what we actually checked
                        'available': False,
                        'status': 'Found (Taken)',
                        'error': None
                    }
                elif data.get('status') == 'FAILED':
                    # User doesn't exist (available)
                    return {
                        'username': username,  # Return original case for display
                        'checked_as': username_to_check,  # Show what we actually checked
                        'available': True,
                        'status': 'Not Found (Available)',
                        'error': None
                    }
            
            # Handle other status codes
            return {
                'username': username,
                'checked_as': username_to_check,
                'available': None,
                'status': f'HTTP Error {response.status_code}',
                'error': f"HTTP {response.status_code}"
            }
            
        except requests.exceptions.RequestException as e:
            return {
                'username': username,
                'checked_as': username_to_check,
                'available': None,
                'status': 'Network Error',
                'error': str(e)
            }
    
    def generate_variations(self, base_word: str) -> List[str]:
        """
        Generate variations of a base word.
        Since usernames are case-insensitive, we only need to check lowercase,
        but we can return a preferred display case.
        """
        base_lower = base_word.lower()
        
        if not self.is_good_username(base_lower):
            return []
        
        # Return the capitalized version for aesthetics (but we'll check as lowercase)
        return [base_word.capitalize()]
    
    def check_usernames_batch(self, usernames: List[str], progress_callback=None) -> List[Dict]:
        """Check a batch of usernames with progress reporting."""
        results = []
        total = len(usernames)
        available_count = 0
        taken_count = 0
        
        for i, username in enumerate(usernames):
            result = self.check_username_availability(username)
            results.append(result)
            
            # Update counters
            if result['available'] is True:
                available_count += 1
                status_emoji = "✅"
            elif result['available'] is False:
                taken_count += 1
                status_emoji = "❌"
            else:
                status_emoji = "⚠️"
            
            if progress_callback:
                progress_callback(i + 1, total, username, result['status'], status_emoji, available_count, taken_count)
            
            # Optional: Save progress periodically
            if (i + 1) % 50 == 0:
                self.save_partial_results(results, f"partial_results_{i+1}.json")
        
        return results
    
    def save_partial_results(self, results: List[Dict], filename: str):
        """Save partial results to avoid losing progress."""
        with open(filename, 'w') as f:
            json.dump(results, f, indent=2)
        print(f"  💾 Saved partial results to {filename}")
    
    def save_results(self, results: List[Dict], base_filename: str = "codeforces_usernames"):
        """Save results in multiple formats."""
        # Filter results
        available = [r for r in results if r['available'] is True]
        unavailable = [r for r in results if r['available'] is False]
        errors = [r for r in results if r['available'] is None]
        
        # Save as JSON with timestamps
        all_results = {
            'metadata': {
                'timestamp': datetime.now().isoformat(),
                'total_checked': len(results),
                'available': len(available),
                'unavailable': len(unavailable),
                'errors': len(errors)
            },
            'results': results,
            'available_usernames': [r['username'] for r in available],
            'unavailable_usernames': [r['username'] for r in unavailable]
        }
        
        with open(f"{base_filename}.json", 'w') as f:
            json.dump(all_results, f, indent=2)
        
        # Save detailed CSV
        with open(f"{base_filename}_detailed.csv", 'w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['Username', 'Available', 'Status'])
            for result in results:
                available_text = 'Yes' if result['available'] is True else 'No' if result['available'] is False else 'Error'
                writer.writerow([result['username'], available_text, result['status']])
        
        # Save available usernames as simple CSV
        if available:
            with open(f"{base_filename}_available.csv", 'w', newline='') as f:
                writer = csv.writer(f)
                writer.writerow(['Username'])
                for result in available:
                    writer.writerow([result['username']])
        
        # Save categorized available usernames
        self.save_categorized_results(available, base_filename)
        
        return all_results
    
    def save_categorized_results(self, available_results: List[Dict], base_filename: str):
        """Categorize and save available usernames by type."""
        word_categories = self.get_dictionary_words()
        categorized = defaultdict(list)
        
        available_usernames = [r['username'] for r in available_results]
        
        for category, words in word_categories.items():
            for result in available_results:
                username_lower = result['username'].lower()
                if username_lower in [w.lower() for w in words]:
                    categorized[category].append(result['username'])
        
        # Add uncategorized
        all_categorized = set()
        for usernames in categorized.values():
            all_categorized.update([u.lower() for u in usernames])
        
        uncategorized = [r['username'] for r in available_results 
                        if r['username'].lower() not in all_categorized]
        if uncategorized:
            categorized['uncategorized'] = uncategorized
        
        with open(f"{base_filename}_categorized.json", 'w') as f:
            json.dump(dict(categorized), f, indent=2)
    
    def view_results(self, filename: str = "codeforces_usernames.json"):
        """View saved results in a formatted way."""
        try:
            with open(filename, 'r') as f:
                data = json.load(f)
            
            print("📊 RESULTS SUMMARY")
            print("=" * 50)
            
            if 'metadata' in data:
                meta = data['metadata']
                print(f"📅 Generated: {meta.get('timestamp', 'Unknown')}")
                print(f"🔢 Total Checked: {meta.get('total_checked', 0)}")
                print(f"✅ Available: {meta.get('available', 0)}")
                print(f"❌ Unavailable: {meta.get('unavailable', 0)}")
                print(f"⚠️  Errors: {meta.get('errors', 0)}")
                print()
            
            if 'available_usernames' in data and data['available_usernames']:
                print("🎉 AVAILABLE USERNAMES:")
                print("-" * 30)
                for i, username in enumerate(data['available_usernames'], 1):
                    print(f"{i:3d}. {username}")
                print()
            
            # Show categorized if available
            categorized_file = filename.replace('.json', '_categorized.json')
            try:
                with open(categorized_file, 'r') as f:
                    categorized = json.load(f)
                
                print("📂 BY CATEGORY:")
                print("-" * 30)
                for category, usernames in categorized.items():
                    if usernames:
                        print(f"{category.upper()}: {', '.join(usernames)}")
                print()
            except FileNotFoundError:
                pass
            
        except FileNotFoundError:
            print(f"❌ Results file not found: {filename}")
        except json.JSONDecodeError:
            print(f"❌ Invalid JSON file: {filename}")
    
    def interactive_word_lookup(self):
        """Interactive mode for looking up synonyms and related words."""
        print("🔍 INTERACTIVE WORD LOOKUP")
        print("=" * 40)
        print("Enter a word to find synonyms and related words")
        print("Type 'quit' to exit")
        print()
        
        while True:
            word = input("Enter word: ").strip().lower()
            
            if word in ['quit', 'exit', 'q']:
                break
            
            if not word:
                continue
            
            print(f"\n🔍 Analyzing '{word}'...")
            print("-" * 30)
            
            # Get definition
            definition = self.get_dictionary_definition(word)
            if definition:
                print(f"📚 Definition: {definition.get('meanings', [{}])[0].get('definitions', [{}])[0].get('definition', 'No definition available')}")
                print()
            
            # Get related words
            related = self.get_related_words_datamuse(word, ['rel_syn', 'rel_hyp', 'rel_hyper'])
            
            all_related_words = []
            for rel_type, words in related.items():
                if words:
                    type_name = {
                        'rel_syn': 'Synonyms',
                        'rel_hyp': 'More Specific',
                        'rel_hyper': 'More General'
                    }.get(rel_type, rel_type)
                    
                    print(f"🔗 {type_name}: {', '.join(words[:10])}")
                    all_related_words.extend(words)
            
            # Always include the original word first
            all_candidate_words = [word]  # Start with the original word
            all_candidate_words.extend(all_related_words)  # Add related words
            
            if all_candidate_words:
                # Filter for good usernames and remove case duplicates
                good_words = []
                seen_lowercase = set()
                
                for candidate_word in all_candidate_words:
                    variations = self.generate_variations(candidate_word)
                    for variation in variations:
                        variation_lower = variation.lower()
                        if variation_lower not in seen_lowercase:
                            seen_lowercase.add(variation_lower)
                            good_words.append(variation)
                
                good_words.sort(key=str.lower)  # Sort case-insensitively
                
                print(f"\n✨ Good username candidates ({len(good_words)}):")
                print(f"  📌 Original: {word.capitalize()}")
                if len(good_words) > 1:
                    print(f"  🔗 Related: {', '.join(good_words[1:21])}")  # Show up to 20 related words
                
                if len(good_words) > 21:
                    print(f"     ... and {len(good_words) - 21} more")
                
                # Offer to check availability
                check = input(f"\nCheck availability of these {min(len(good_words), 20)} usernames? (y/n): ").lower().strip()
                if check == 'y':
                    print("\n🔍 Checking availability...")
                    
                    def progress_cb(current, total, username, status, emoji, available, taken):
                        print(f"  [{current:2d}/{total:2d}] {emoji} {username:15} - {status}")
                    
                    results = self.check_usernames_batch(good_words[:20], progress_cb)
                    
                    available_results = [r for r in results if r['available'] is True]
                    if available_results:
                        print(f"\n🎉 Found {len(available_results)} available usernames:")
                        for result in available_results:
                            print(f"  ✅ {result['username']}")
                    else:
                        print("\n😞 No available usernames found in this batch")
            
            print("\n" + "="*50 + "\n")
    
    def run_check(self, custom_words: List[str] = None, use_built_in: bool = True):
        """Run the complete username checking process."""
        print("🔍 Codeforces Username Availability Checker")
        print("=" * 50)
        
        # Collect all words to check
        all_words = []
        
        if use_built_in:
            print("📚 Loading built-in dictionary...")
            word_categories = self.get_dictionary_words()
            for category, words in word_categories.items():
                print(f"  • {category}: {len(words)} words")
                all_words.extend(words)
        
        if custom_words:
            print(f"➕ Adding {len(custom_words)} custom words...")
            all_words.extend(custom_words)
        
        # Generate username variations
        print("🔄 Generating username variations...")
        all_usernames = []
        for word in set(all_words):  # Remove duplicates
            variations = self.generate_variations(word)
            all_usernames.extend(variations)
        
        # Remove duplicates based on lowercase (since usernames are case-insensitive)
        # but keep the preferred case version
        seen_lowercase = set()
        unique_usernames = []
        for username in all_usernames:
            username_lower = username.lower()
            if username_lower not in seen_lowercase and self.is_good_username(username):
                seen_lowercase.add(username_lower)
                unique_usernames.append(username)
        
        unique_usernames.sort(key=str.lower)  # Sort case-insensitively
        
        print(f"✅ Generated {len(unique_usernames)} unique usernames to check")
        print(f"   (Removed {len(all_usernames) - len(unique_usernames)} case duplicates)")
        print(f"⏱️  Estimated time: {len(unique_usernames) * self.rate_limit_delay / 60:.1f} minutes")
        
        # Ask for confirmation
        proceed = input("\n🚀 Proceed with checking? (y/n): ").lower().strip()
        if proceed != 'y':
            print("❌ Cancelled.")
            return
        
        print(f"\n🔍 Starting username availability check...")
        print(f"{'Progress':<12} {'Username':<15} {'Status':<20} {'Available':<10} {'Taken':<10}")
        print("-" * 80)
        
        def progress_callback(current, total, username, status, emoji, available_count, taken_count):
            percent = (current / total) * 100
            print(f"[{current:3d}/{total:3d}] {percent:5.1f}% {emoji} {username:<15} {status:<20} {available_count:<10} {taken_count:<10}")
        
        # Check usernames
        results = self.check_usernames_batch(unique_usernames, progress_callback)
        
        # Save results
        print(f"\n💾 Saving results...")
        summary = self.save_results(results)
        
        # Print summary
        print(f"\n📊 FINAL SUMMARY")
        print("=" * 40)
        meta = summary['metadata']
        print(f"📅 Completed: {meta['timestamp']}")
        print(f"🔢 Total checked: {meta['total_checked']}")
        print(f"✅ Available: {meta['available']}")
        print(f"❌ Unavailable: {meta['unavailable']}")
        print(f"⚠️  Errors: {meta['errors']}")
        
        if meta['available'] > 0:
            print(f"\n🎉 Found {meta['available']} available usernames!")
            print("📁 Results saved to:")
            print("  • codeforces_usernames.json (complete results)")
            print("  • codeforces_usernames_detailed.csv (all results with status)")
            print("  • codeforces_usernames_available.csv (available only)")
            print("  • codeforces_usernames_categorized.json (by category)")
            
            # Show first few available usernames
            if summary['available_usernames']:
                print(f"\n🌟 First few available usernames:")
                for i, username in enumerate(summary['available_usernames'][:10], 1):
                    print(f"  {i:2d}. {username}")
                if len(summary['available_usernames']) > 10:
                    print(f"     ... and {len(summary['available_usernames']) - 10} more!")
        
        return results


def main():
    """Main function with interactive menu."""
    checker = CodeforcesUsernameChecker()
    
    while True:
        print("\n🔍 CODEFORCES USERNAME CHECKER")
        print("=" * 40)
        print("1. 🚀 Run full username check")
        print("2. 🔍 Interactive word lookup (synonyms)")
        print("3. 📊 View saved results")
        print("4. ❌ Exit")
        
        choice = input("\nSelect option (1-4): ").strip()
        
        if choice == '1':
            # Ask about custom words
            custom_input = input("\nEnter custom words (comma-separated) or press Enter to skip: ").strip()
            custom_words = [w.strip() for w in custom_input.split(',') if w.strip()] if custom_input else []
            
            use_built_in = input("Use built-in dictionary? (y/n): ").lower().strip() != 'n'
            
            checker.run_check(custom_words=custom_words, use_built_in=use_built_in)
        
        elif choice == '2':
            checker.interactive_word_lookup()
        
        elif choice == '3':
            filename = input("Results filename (default: codeforces_usernames.json): ").strip()
            if not filename:
                filename = "codeforces_usernames.json"
            checker.view_results(filename)
        
        elif choice == '4':
            print("👋 Goodbye!")
            break
        
        else:
            print("❌ Invalid option. Please choose 1-4.")

if __name__ == "__main__":
    main()
