//
// Created by sebastian on 21.06.19.
//

#pragma once

#include <vector>
#include <string>
#include <string_view>

struct PositionInfo {
    std::size_t start;
    std::size_t stop;
};

enum class Architectures {
    AVR,
    ARM
};

class ProcessDatabase {
private:
    Architectures mArch;
    std::string mAssemblyLocation;
    std::string mFileContent;
    std::vector<std::string> mSections;

    std::size_t mCurrentPosition = 0;
    std::string mCurrentAssembly;
    std::vector<std::vector<std::string>> mCurrentParsedAssembly;
    std::size_t mCurrentTiming = 0;
public:
    std::string START_DELIMITER;
    std::string STOP_DELIMITER;

    void fileLocation(const std::string& fileLocation) noexcept;

    [[nodiscard]] std::string fileLocation() const noexcept;

    void arch(const std::string& fileLocation) noexcept;

    [[nodiscard]] Architectures arch() const noexcept;

    void fileContents(const std::string& fileLocation) noexcept;

    [[nodiscard]] std::string fileContents() const noexcept;

    void addSection(const std::string& section) noexcept;

    void clearSections() noexcept;

    [[nodiscard]] const std::vector<std::string>& getSections() const noexcept;

    [[nodiscard]] const std::string popSection() noexcept;

    void position(std::size_t position) noexcept;

    [[nodiscard]] std::size_t position() const noexcept;

    [[nodiscard]] std::string currentAssembly() const noexcept;

    void currentAssembly(const std::string& assembly) noexcept;

    [[nodiscard]] const std::vector<std::vector<std::string>>& currentparsedAssembly() const noexcept;

    void addParsedAssembly(const std::vector<std::string>& assembly) noexcept;

    void clearParsedAssembly();

    void timing(std::size_t timing) noexcept;

    [[nodiscard]] std::size_t timing() const noexcept;

    void clearTemporary() noexcept;
};



