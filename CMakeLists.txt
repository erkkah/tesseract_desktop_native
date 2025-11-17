cmake_minimum_required(VERSION 3.25)
project(tesseract)
add_library(${PROJECT_NAME} SHARED main.c)

IF(WIN32)
    set(CMAKE_C_STANDARD_LIBRARIES "-static-libgcc -Wl,-Bstatic -lpthread -Wl,-Bdynamic ${CMAKE_C_STANDARD_LIBRARIES}")
    target_link_options(${PROJECT_NAME} PRIVATE -s)
    target_link_libraries(${PROJECT_NAME}
        -Wl,--whole-archive libtesseract.a -Wl,--no-whole-archive libleptonica.a
    )
ELSEIF(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "14.00" CACHE STRING "OS X deployment target" FORCE)
    target_compile_options(${PROJECT_NAME} PRIVATE -fvisibility=hidden)
    target_link_libraries(${PROJECT_NAME}
      "-framework accelerate"
      )
    target_link_libraries(${PROJECT_NAME} -force_load
        ${STATICS_ROOT}/libleptonica.a
        ${STATICS_ROOT}/libtesseract.a
        ${STATICS_ROOT}/libpng.a
        ${STATICS_ROOT}/libjpeg.a
        ${STATICS_ROOT}/libopenjp2.a
        ${STATICS_ROOT}/libwebp.a
        ${STATICS_ROOT}/libwebpmux.a
        ${STATICS_ROOT}/libtiff.a
        ${STATICS_ROOT}/libzstd.a
        ${STATICS_ROOT}/libgif.a
        ${STATICS_ROOT}/liblzma.a
        ${STATICS_ROOT}/libsharpyuv.a
        z
    )
ENDIF()
