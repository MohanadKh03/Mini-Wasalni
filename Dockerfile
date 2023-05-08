FROM alpine:latest

WORKDIR /usr/src/app

# Install required dependencies and the g++ compiler
RUN apk update && \
    apk add --no-cache bash libstdc++ libc6-compat g++

# Copy the C++ code to the working directory
COPY . .

# Compile the C++ code into an executable named "myprogram"
RUN g++ -o myprogram main.cpp

# Set the entry point to run the "myprogram" executable
ENTRYPOINT ["./myprogram"]
