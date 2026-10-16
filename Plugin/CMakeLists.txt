paraview_add_plugin(SZ3ImageDataReader
  REQUIRED_ON_CLIENT
  REQUIRED_ON_SERVER
  VERSION "2.0"
  MODULES SZ3ImageDataReader::vtkSZ3ImageDataReader
  MODULE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../Reader/vtk.module")
