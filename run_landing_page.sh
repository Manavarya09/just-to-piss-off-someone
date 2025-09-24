#!/bin/bash

# Modern Landing Page - GTK Application Runner
# This script launches the landing page application

echo "🚀 Launching Modern Landing Page Application..."
echo "   Built with GTK3 and C"
echo ""

# Check if the executable exists
if [ ! -f "./landing_page" ]; then
    echo "❌ Error: landing_page executable not found!"
    echo "   Please run 'make' to build the application first."
    exit 1
fi

# Check if GTK is available
if ! pkg-config --exists gtk+-3.0; then
    echo "❌ Error: GTK3 not found!"
    echo "   Please install GTK3 development libraries:"
    echo "   brew install gtk+3 pkg-config"
    exit 1
fi

echo "✅ All dependencies found"
echo "📱 Starting application..."
echo ""
echo "Features:"
echo "  • Beautiful gradient background"
echo "  • Hero section with call-to-action"
echo "  • Three feature cards in a grid"
echo "  • Responsive design"
echo "  • Smooth hover animations"
echo ""

# Launch the application
./landing_page

echo ""
echo "👋 Thanks for using the Modern Landing Page application!"