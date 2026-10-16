# Build SZ3Compat (multi-version SZ3 decompression with dynamic plugins)
add_subdirectory(SZ3Compat)

set(classes
  vtkSZ3ImageDataReader)

vtk_module_add_module(SZ3ImageDataReader::vtkSZ3ImageDataReader
  CLASSES ${classes})

vtk_module_link(SZ3ImageDataReader::vtkSZ3ImageDataReader
  PRIVATE
    SZ3Compat
    ${CMAKE_DL_LIBS})

vtk_module_include(SZ3ImageDataReader::vtkSZ3ImageDataReader
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/SZ3Compat/include)

paraview_add_server_manager_xmls(
  XMLS
    SZ3ImageDataReader.xml)
