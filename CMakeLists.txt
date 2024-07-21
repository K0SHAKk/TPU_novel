cmake_minimum_required(VERSION 3.0.0)
project(TPU_novel VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB project_GLOB
    src/*
)

add_executable(TPU_novel ${project_GLOB})