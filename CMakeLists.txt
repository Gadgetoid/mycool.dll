cmake_minimum_required(VERSION 3.20)
project(mycool C)
include(Grimace)

grimace_add_library(mycool src/mycool.c
    EXPORTS BSQCORE_Version EvaluationStatus GetCEInformation ShowAboutBox ShowAboutBoxEx)

grimace_package("mycool" PROVIDER "me"
    TARGETS mycool DIRECTORY "\\Windows")
