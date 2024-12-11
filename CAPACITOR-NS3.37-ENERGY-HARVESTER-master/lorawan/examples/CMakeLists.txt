build_lib_example(
  NAME complete-network-example
  SOURCE_FILES complete-network-example.cc
  LIBRARIES_TO_LINK
  ${libcore} ${liblorawan}
)

# build_lib_example(
#   NAME energy-model-example
#   SOURCE_FILES energy-model-example.cc
#   LIBRARIES_TO_LINK
#     ${libcore}
#     ${liblorawan}
# )

build_lib_example(
  NAME energy-single-device-example
  SOURCE_FILES energy-single-device-example.cc
  LIBRARIES_TO_LINK
    ${libcore}
    ${liblorawan}
)

build_lib_example(
  NAME network-analysis-capacitor
  SOURCE_FILES network-analysis-capacitor.cc
  LIBRARIES_TO_LINK
    ${libcore}
    ${liblorawan}
)

build_lib_example(
  NAME network-server-example
  SOURCE_FILES network-server-example.cc
  LIBRARIES_TO_LINK
    ${libcore}
    ${liblorawan}
)

build_lib_example(
  NAME simple-network-example
  SOURCE_FILES simple-network-example.cc
  LIBRARIES_TO_LINK
    ${libcore}
    ${liblorawan}
)

