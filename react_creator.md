## Install Tailwind CSS v4 with React and Vite

Here's the proper step-by-step guide:

### 1. Create a new Vite + React project

```bash
npm create vite@latest my-project -- --template react
cd my-project
```

### 2. Install Tailwind CSS v4 and the Vite plugin

```bash
npm install tailwindcss @tailwindcss/vite
```

### 3. Update your `vite.config.js` file

```javascript
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'

export default defineConfig({
  plugins: [
    react(),
    tailwindcss()
  ],
})
```

### 4. Add Tailwind directives to your CSS and adjust the width of the page (half page by default for some reason)

In your `src/index.css` file, add:

```css
@import 'tailwindcss';

html, body, #root {
    width: 100%;
    margin: 0;
    padding: 0;
    overflow-x: hidden;
}
```

That's it! Tailwind CSS v4 has significantly simplified the setup process - it no longer requires:
- A `tailwind.config.js` file (it's optional)
- A `postcss.config.js` file
- Content path configuration
- Multiple directives in your CSS

Tailwind v4 now uses sensible defaults and has automatic content detection, so you don't need to manually configure the content paths. The CSS import system is also built-in, so you don't need additional plugins.

### 6. Copy website contents into App.jsx

Update App.jsx to make your website. Claude generated code can go here and replace this code.

### 7. Start your development server

```bash
npm run dev
```
