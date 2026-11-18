#pragma once

#include <cstddef>

class IImportadorActividades {
public:
    virtual ~IImportadorActividades() = default;
    virtual std::size_t importar() const = 0;
};
