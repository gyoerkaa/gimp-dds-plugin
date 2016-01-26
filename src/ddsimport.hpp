#ifndef DDSIMPORT_H
#define DDSIMPORT_H

class DDSImport {
public:
    DDSImport();
    bool open(const std::string name);
    bool close();

private:
    std::string m_filename;

    void init();
};

#endif

