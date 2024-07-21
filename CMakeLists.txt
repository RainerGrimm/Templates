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


set(example_programs    built_inLiteral
    templateClassTemplate
    regularSemiRegular
    tooGeneric
    tooSpecific
    typeErasureOO
    templateTagDispatching
    templateTypeDeduction
    foldExpression
    dispatchDynamicPolymorphism
    templateClassTemplateMethods
    templateSpecializationPrimary
    templateVariadicTemplates
    templateFill
    conceptsSpecialization
    genericLambdaTemplate
    templateClassTemplateTypeFriendship
    templateAutomaticReturnType
    templateClassTemplateInheritance
    templatePower
    advanceConstexprIf
    templateFunctionsTemplates
    templateCRTPRelational
    templatePrimeNumber
    templateInstantiation
    allAnyNone
    conceptsDefinitionEqual
    templateLookup
    templateSpecialization
    conceptMemberFunction
    templateArgumentDeductionClass
    templatesTraits
    templateSpecializationFull
    templatesPolicy
    conceptsDefinitionOrdering
    constExpression
    templatePerfectForwarding
    conceptsOverloadingFunctionTemplates
    typeErasure
    templateClassTemplateGeneralFriendship
    constExpressionCpp14
    placeholders
    vectorArithmeticExpressionTemplatesExtend
    advanceTagDispatching
    templateTypes
    conceptsIntegralVariations
    vectorArithmeticOperatorOverloading
    templateTypeParameter
    dispatchStaticPolymorphism
    conceptsOverloading
    typeRequirements
    vectorArithmeticExpressionTemplates
    templateTypeManipulation
    conceptClassTemplate
    templateDefaultArgument
    signedUnsignedIntegrals
    abbreviatedFunctionTemplates
    templateArgumentDeduction
    templateFunctionsTemplatesOverloading
    templateTemplateTemplatesParameter
    templateCRTP
    constexprIf
    templateSpecializationExternal
    templateClassTemplateSpecialFriendship
   )

foreach(example_program ${example_programs})
  set(sources ${example_program}.cpp)
  source_group("Source Files" FILES{sources})
  add_executable(${example_program} ${sources})
endforeach()
