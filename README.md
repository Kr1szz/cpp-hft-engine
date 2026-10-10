C++ HFT Engine

A beginner-friendly, single-threaded Limit Order Book and Matching Engine built with C++17. This project explores the fundamentals of high-frequency trading (HFT), order matching, and low-latency system development.

Features

Order management and validation

Limit order book implementation

Price-time priority matching

Trade execution and partial fills

Order cancellation

Unit testing and performance benchmarking

Tech Stack

Language: C++17

Build System: CMake + Ninja

Testing: CTest

Platform: Linux

Getting Started

Build

cmake -S . -B build -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug
cmake --build build

Run

./build/hft_engine

Test

ctest --test-dir build --output-on-failure

Project Goals

Implement a correct order book and matching engine.

Understand price-time priority and trade execution.

Write comprehensive tests for matching and cancellation.

Benchmark throughput and latency.

Explore profiling and low-latency C++ optimizations.