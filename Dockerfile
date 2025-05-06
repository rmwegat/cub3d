# Use an official GCC image with dependencies
FROM debian:bullseye

# Install build tools and libraries (add SDL/X dependencies if needed)
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libglfw3 \
    libglfw3-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libx11-dev \
    libxrandr-dev \
    libxi-dev \
    libxcursor-dev \
    libxinerama-dev \
    make \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Create working directory
WORKDIR /app

# Copy all files into the container
COPY . .

# Build the project using Makefile
RUN make

# Default command (replace with map file as needed)
CMD ["./cub3d", "maps/square.cub"]