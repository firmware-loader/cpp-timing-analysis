//
// Created by sebastian on 21.06.19.
//

#include "ProcessDatabase.h"

void ProcessDatabase::fileLocation(const std::string &fileLocation) noexcept {
    mAssemblyLocation = fileLocation;
}

std::string ProcessDatabase::fileLocation() const noexcept {
    return mAssemblyLocation;
}

void ProcessDatabase::fileContents(const std::string &fileLocation) noexcept {
    mFileContent = fileLocation;
}

std::string ProcessDatabase::fileContents() const noexcept {
    return mFileContent;
}

const std::vector<std::string> &ProcessDatabase::getSections() const noexcept {
    return mSections;
}

void ProcessDatabase::addSection(const std::string &section) noexcept {
    mSections.push_back(section);
}

void ProcessDatabase::clearSections() noexcept {
    mSections.clear();
}

const std::string ProcessDatabase::popSection() noexcept {
    const auto back = mSections.back();
    mSections.pop_back();
    return back;
}

void ProcessDatabase::currentAssembly(const std::string &assembly) noexcept {
    mCurrentAssembly = assembly;
}

std::string ProcessDatabase::currentAssembly() const noexcept {
    return mCurrentAssembly;
}

const std::vector<std::vector<std::string>> &ProcessDatabase::currentparsedAssembly() const noexcept {
    return mCurrentParsedAssembly;
}

void ProcessDatabase::addParsedAssembly(const std::vector<std::string> &assembly) noexcept {
    mCurrentParsedAssembly.emplace_back(assembly);
}

void ProcessDatabase::clearParsedAssembly() {
    mCurrentParsedAssembly.clear();
}

void ProcessDatabase::timing(std::size_t timing) noexcept {
    mCurrentTiming = timing;
}

std::size_t ProcessDatabase::timing() const noexcept {
    return mCurrentTiming;
}

void ProcessDatabase::position(std::size_t position) noexcept {
    mCurrentPosition = position;
}

std::size_t ProcessDatabase::position() const noexcept {
    return mCurrentPosition;
}

void ProcessDatabase::clearTemporary() noexcept {
    mCurrentTiming = 0;
    mCurrentAssembly = "";
    mCurrentParsedAssembly = {};
    mCurrentPosition = 0;
}

void ProcessDatabase::arch(const std::string &fileLocation) noexcept {
    std::string tmpArch = fileLocation;
    std::transform(tmpArch.begin(), tmpArch.end(), tmpArch.begin(), ::tolower);
    std::string comment = "";
    if(tmpArch == "arm") {
        mArch = Architectures::ARM;
        comment = "@";
    } else if(tmpArch == "avr") {
        mArch = Architectures ::AVR;
        comment = ";";
    } else {
        mArch = Architectures ::AVR;
        comment = ";";
    }

    START_DELIMITER = comment + "START_MEASUREMENT\n";
    STOP_DELIMITER = comment + "STOP_MEASUREMENT\n";
}

Architectures ProcessDatabase::arch() const noexcept {
    return mArch;
}
