#ifndef LARAVEL_COMPILER_H
#define LARAVEL_COMPILER_H
#include <string>
#include "lexer/lexer.h"
#include "preprocessor/preprocessor.h"

class laravel_compiler {
private:
    preprocessor * sourcePreprocessor = new preprocessor();
    lexer * lexicalAnalyzer = new lexer();
protected:
    std::string projectPath;
public:
    /**
     * @brief Construct a new laravel compiler object
     * @param {std::string} projectPath
     */
    explicit laravel_compiler(std::string projectPath);
};


#endif //LARAVEL_COMPILER_H
