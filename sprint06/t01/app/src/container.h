#pragma once
#include <iostream>
#include <string>

enum class LockpickDifficulty {
    None = 0,
    Novice = 25,
    Apprentice = 40,
    Adept = 60,
    Expert = 80,
    Master = 100
};

class IOpenable {
public:
    virtual bool tryToOpen(LockpickDifficulty difficulty) = 0;
};

class ILockable {
public:
    virtual bool isLocked() const = 0;
    virtual LockpickDifficulty lockDifficulty() const = 0;
};

class Container : public ILockable, public IOpenable {
public:
    Container(bool isLocked, const LockpickDifficulty difficulty) : m_isLocked(isLocked), m_difficulty(difficulty) {}
    virtual ~Container() = default;
    LockpickDifficulty lockDifficulty() const override {
        return m_difficulty;
    }

    bool isLocked() const override{
        return m_isLocked;
    }

    bool tryToOpen(LockpickDifficulty skill) override {
        if (skill < m_difficulty)
            return false;
        m_isLocked = false;
        return true;
    }
    virtual std::string name() const = 0;

private:
    bool m_isLocked{false};
    LockpickDifficulty m_difficulty;
};

class Barrel : public Container {
public:
    Barrel() : Container(true, LockpickDifficulty::None) {}
    ~Barrel() = default;
    std::string name() const override {
        return m_name;
    }

private:
    static inline std::string m_name = "Barrel";
};

class Chest : public Container {
public:
    Chest(bool isLocked, LockpickDifficulty skills) : Container(isLocked, skills) {}
    ~Chest() = default;
    std::string name() const override {
        return m_name;
    }

private:
    static inline std::string m_name = "Chest";
};

class Safe : public Container {
public:
    Safe(bool isLocked, LockpickDifficulty skills) : Container(isLocked, skills) {}
    ~Safe() = default;
    std::string name() const override {
        return m_name;
    }

private:
    static inline std::string m_name = "Safe";
};

class Player final {
public:
    explicit Player(const std::string& name) : m_name(name) {}

    void openContainer(Container* container) {
        if (container->tryToOpen(m_lockpickSkill) == true)
            std::cout << m_name << " successfully opened " << container->name() << std::endl;
        else
            std::cout << m_name << " skill is too low to open " << container->name() << std::endl;
    }
    void setLockpickSkill(LockpickDifficulty skill) {
        m_lockpickSkill = skill;
    }

private:
    LockpickDifficulty m_lockpickSkill{LockpickDifficulty::None};
    std::string m_name;
};