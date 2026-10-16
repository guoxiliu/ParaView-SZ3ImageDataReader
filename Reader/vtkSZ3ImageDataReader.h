#ifndef vtkSZ3ImageDataReader_h
#define vtkSZ3ImageDataReader_h

#include "vtkSZ3ImageDataReaderModule.h" // for export macro
#include "vtkImageAlgorithm.h"

#include <string>
#include <vector>

class VTKSZ3IMAGEDATAREADER_EXPORT vtkSZ3ImageDataReader : public vtkImageAlgorithm
{
public:
  static vtkSZ3ImageDataReader* New();
  vtkTypeMacro(vtkSZ3ImageDataReader, vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);

  void SetDomainDimensions(int x, int y, int z);
  void GetDomainDimensions(int& x, int& y, int& z);

  void SetDoublePrecision(int flag) { this->UseDoublePrecision = flag; this->Modified(); }
  int GetDoublePrecision() const { return this->UseDoublePrecision; }

protected:
  vtkSZ3ImageDataReader();
  ~vtkSZ3ImageDataReader();
  int RequestInformation(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;
  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  char* FileName;
  int DomainDimensions[3];
  int UseDoublePrecision;

private:
  vtkSZ3ImageDataReader(const vtkSZ3ImageDataReader&);
  void operator=(const vtkSZ3ImageDataReader&);

  template <typename T>
  void Decompress(vtkImageData* output, std::vector<char>& compressedBuffer);
};

#endif
