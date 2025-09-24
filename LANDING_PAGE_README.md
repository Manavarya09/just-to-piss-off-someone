Modern Landing Page - GTK Application

A beautiful, responsive landing page application built with GTK3 and C, featuring modern design elements, smooth animations, and professional styling.

Features

- Hero Section: Eye-catching header with gradient background, bold title, subtitle, and call-to-action button
- Features Grid: Three feature cards with icons, titles, and descriptions in a responsive grid layout
- Footer: Clean footer with copyright information
- Modern Styling: CSS3 animations, gradients, shadows, and hover effects
- Responsive Design: Adapts to different window sizes
- Clean Code: Well-structured C code with modular functions

Screenshots

The application features:
- Gradient purple background
- Glassmorphism design elements
- Smooth hover animations
- Professional typography
- Card-based feature layout

Prerequisites

Before building and running the application, you need to install GTK3 development libraries.

macOS (using Homebrew)

```bash
brew install gtk+3 pkg-config
```

Ubuntu/Debian

```bash
sudo apt-get update
sudo apt-get install libgtk-3-dev pkg-config
```

Fedora/CentOS/RHEL

```bash
sudo dnf install gtk3-devel pkgconfig
# or for older versions:
# sudo yum install gtk3-devel pkgconfig
```

Building and Running

Quick Start

Using the provided Makefile:

```bash
make install-deps
make
make run
make run
```

Manual Compilation

If you prefer to compile manually:

```bash
gcc -Wall -Wextra -O2 `pkg-config --cflags gtk+-3.0` -o landing_page landing_page.c `pkg-config --libs gtk+-3.0`
./landing_page
```

Makefile Targets

- `make` or `make all` - Build the application
- `make run` - Build and run the application
- `make clean` - Remove build files
- `make install-deps` - Install GTK3 dependencies (macOS only)
- `make help` - Show available targets

Code Structure

The application is organized into several key functions:

Core Functions

- `main()` - Application entry point and GTK initialization
- `create_hero_section()` - Creates the hero section with title, subtitle, and button
- `create_features_section()` - Creates the features grid with three cards
- `create_footer_section()` - Creates the footer with copyright text
- `apply_styles()` - Applies CSS styling to the application

Event Handlers

- `on_get_started_clicked()` - Handles the "Get Started" button click
- `on_window_destroy()` - Handles window close event
- `on_button_enter()`/`on_button_leave()` - Button hover events (handled by CSS)

Styling

The application uses embedded CSS for modern styling including:
- Gradient backgrounds
- Glassmorphism effects (frosted glass appearance)
- Smooth transitions and animations
- Professional typography
- Responsive card layouts
- Button hover effects

Customization

Modifying Content

To customize the text content, modify these sections in `landing_page.c`:

- **Hero Title**: Line 185 - Change "Welcome to the Future"
- **Hero Subtitle**: Lines 190-193 - Update the description
- **Features**: Lines 241-244 - Update the feature data structure

Styling Changes

The CSS styles are defined in the `css_styles` constant (lines 25-132). You can modify:
- Colors and gradients
- Font sizes and families
- Spacing and padding
- Animation effects
- Background styles

Adding More Features

To add more feature cards, simply extend the features array and update the loop counter in the `create_features_section()` function.

Technical Details

Dependencies

- GTK+ 3.0 or later
- GCC compiler
- pkg-config for library detection

Architecture

- **Language**: C
- **GUI Framework**: GTK3
- **Styling**: CSS3 via GTK's CSS provider
- **Layout**: Box containers and Grid widgets
- **Event System**: GTK signal/callback system

Performance

The application is optimized for performance with:
- Efficient widget creation and management
- CSS-based styling (hardware accelerated where supported)
- Minimal memory footprint
- Fast startup time

Troubleshooting

Common Issues

1. **GTK not found**: Make sure GTK3 development libraries are installed
2. **pkg-config errors**: Install pkg-config package
3. **Compilation errors**: Check that all dependencies are properly installed

Getting Help

If you encounter issues:
1. Check that all prerequisites are installed
2. Verify GTK3 installation with: `pkg-config --modversion gtk+-3.0`
3. Ensure you're using a compatible compiler (GCC recommended)

License

This project is open source and available under the MIT License.

Contributing

Feel free to submit issues, feature requests, or pull requests to improve this application.