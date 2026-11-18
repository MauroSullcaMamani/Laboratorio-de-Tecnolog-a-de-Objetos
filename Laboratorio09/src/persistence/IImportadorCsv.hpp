#pragma once

#include <cstddef>

class IImportadorCsv {
public:
    virtual ~IImportadorCsv() = default;
    virtual std::size_t importar() const = 0;
};
