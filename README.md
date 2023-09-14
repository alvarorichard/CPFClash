# CPFClash
This project is a comparison between different implementations of CPF (Cadastro de Pessoas Físicas, or "Registration of Physical Persons" in English) generators across various programming languages including Rust, Go, C++, and Zig. The goal is to provide a practical example to learn and compare idiomatic aspects and performance characteristics of each language.

## Requirements

* Rust (Cargo)
* Go
* C++ (Compiler such as g++, clang++)
* Docker (Optional)
  
  ## How to Run the Project

 #### Rust
  
  Navigate to the folder where the Rust project is located, then run:
 ```shell
  cargo run
 ```
 #### Go

Navigate to the folder where the Go project is located, then run:

```shell
go run main.go
```
#### C++
Compile the C++ code using a C++ compiler and then run the binary:

```shell
g++ -o cpf_generator main.cpp cpf.cpp cpf.hpp
./cpf_generator
```
#### Zig

Navigate to the folder where the Zig project is located, then run:

```shell
zig build-exe main.zig
./main
```
## How to Run Using Docker

to run the project using Docker, you can create a `Dockerfile` for each language implementation. Here is a generic example for a Go implementation:


```shell
# Use a base image
FROM golang:latest

# Set the working directory
WORKDIR /app

# Copy local content into the container
COPY . .

# Compile the program
RUN go build -o main .

# Run the program
CMD ["./main"]
```
After creating the `Dockerfile`, you can build and run the container:

```shell
docker build -t cpf_generator_go .
docker run cpf_generator_go
```

## About the CPF Generator Showdown

This project serves as a practical exercise to understand the differences between various programming languages in the context of a Brazilian domain problem: the generation of valid CPFs. Each implementation has its unique intricacies, such as:

* How the language handles random number generation.
* Idiomatic practices for code structuring and memory management.
* The use of standard libraries and specific language features.

This project also serves as a good basis to learn how to set up and run projects in each of these languages, both locally and via Docker.