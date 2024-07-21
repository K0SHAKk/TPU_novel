cmake_minimum_required(VERSION 3.10)
project(TPU_novel)

file(GLOB project_GLOB
    src/*
)

add_executable(TPU_novel ${project_GLOB})