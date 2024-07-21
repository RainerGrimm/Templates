# Require a recent version of cmake
cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

# This project is C++ based.
project(seminar)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_CXX_FLAGS "-O3 -Wall -std=c++20 -pthread")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8)
	    message(WARNING "!!!! GCC versions must be at least 8 !!!!")
        message(WARNING "!!!! Adust the makefile to build with a different compiler. !!!!")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(CMAKE_CXX_FLAGS "-O3 -Wall -std=c++20 -pthread")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5)
        message(WARNING "!!!! Clang version must be at least 5 !!!!")
		message(WARNING "!!!! Adust the makefile to build with a different compiler. !!!!")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(CMAKE_CXX_FLAGS "/Ox /EHsc /std:c++20")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.15)    
        message(WARNING "!!!! MSVC version must be at least 19.15 !!!!")
    endif()	
else()
    message(WARNING "!!! You are using an unsupported compiler! Compilation has only been tested with GCC >= 8, Clang >= 5, or MSVC >= 19.15. !!!")
endif()
    

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

set(CMAKE_VERBOSE_MAKEFILE on)


set(example_programs    templatesPolicyMap
    templatesPolicyDecreasing
    dispatchSwitch
    conceptArithmetic
    dispatchGeneric
    gcdVariations
    polymorph
    power3
    sumConcepts
    templateClassTemplateMethods
    templateNonTypeParameter
    templateGcdCommon
    templateCRTPCheck
    functionTemplateArgumentDeductionReference
    power2
    dispatchPolymorphism
    advanceTagDispatchingImplementation
    templateCRTPRelational
    led
    templateGcdIntegral
    templateGcd
    templateGcdConditional
    power1
    advanceConstexprIfImplementation
    dispatchHashtable
    templateClassTemplateMethods3
    printf
    templateTagDispatchingImplementation
    conceptArithmeticTwoTypes
    dispatchIf
    sum
    templateTypeTraitsModifications
    vectorArithmeticExpressionTemplatesExtend
    functionTemplateArgumentDeductionUniversalReference
    templateInstantiationInvalid
    monitorObject
    templateClassTemplateMethods2
    templateTypes
    dispatchConcepts
    templateFactorial
    templateTraitsPrimary
    typeErasureTypeInfo
    functionTemplateArgumentDeductionValue
    vectorArithmeticExpressionTemplatesImproved
    templateGcdSFINAE
    templatesCRTPShareMe
   )

foreach(example_program ${example_programs})
  set(sources ${example_program}.cpp)
  source_group("Source Files" FILES{sources})
  add_executable(${example_program} ${sources})
endforeach()
