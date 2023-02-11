#pragma once

#define PYLLVM_CONCAT(a, b) a##b
#define PYLLVM_CONCAT2(a, b) PYLLVM_CONCAT(a, b)
#define PYLLVM_UNIQUE_NAME(name) PYLLVM_CONCAT2(name, __COUNTER__)
