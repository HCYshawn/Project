#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 转发声明
class Command;
class WindowHandler;
class HelpHandler;

// 抽象命令类
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

// 请求接收者
class WindowHandler
{
public:
    void minimize()
    {
        cout << "窗口最小化." << endl;
    }
};

// 请求接收者
class HelpHandler
{
public:
    void display()
    {
        cout << "显示帮助信息." << endl;
    }
};

// 具体命令类
class MinimizeCommand : public Command
{
    WindowHandler *whobj;

public:
    explicit MinimizeCommand(WindowHandler *wh) : whobj(wh) {}
    void execute() override
    {
        if (whobj)
            whobj->minimize();
    }
};

// 具体命令类
class HelpCommand : public Command
{
    HelpHandler *hhobj;

public:
    explicit HelpCommand(HelpHandler *hh) : hhobj(hh) {}
    void execute() override
    {
        if (hhobj)
            hhobj->display();
    }
};

// 请求调用者
class FunctionButton
{
    string name;      // 功能键名称
    Command *command; // 维持一个抽象命令对象的引用

public:
    explicit FunctionButton(const string &btnName) : name(btnName), command(nullptr) {}

    string getName() const { return name; }

    void setCommand(Command *cmd)
    {
        command = cmd;
    }

    void onClick() // 调用命令对象的execute()方法
    {
        if (command)
            command->execute();
    }
};

// “功能键设置”窗口类
class FBSettingWindow
{
    string title;                           // 窗口标题
    vector<FunctionButton> functionButtons; // 功能键集合

public:
    explicit FBSettingWindow(const string &windowTitle) : title(windowTitle) {}

    void setTitle(const string &newTitle)
    {
        title = newTitle;
    }

    string getTitle() const
    {
        return title;
    }

    void addFunctionButton(const FunctionButton &fb)
    {
        functionButtons.push_back(fb);
    }

    void display()
    {
        cout << "----- " << title << " -----" << endl;
        for (auto &btn : functionButtons)
        {
            cout << "[" << btn.getName() << "] "; // 显示功能键名称
            btn.onClick();                        // 调用功能键对应的命令对象的execute()方法
        }
        cout << "-----------------------" << endl;
    }
};

// Client code
int main()
{
    WindowHandler windowHandler;
    HelpHandler helpHandler;

    // Create commands
    MinimizeCommand minimizeCmd(&windowHandler);
    HelpCommand helpCmd(&helpHandler);

    // Create buttons with commands
    FunctionButton btnMinimize("Minimize");
    btnMinimize.setCommand(&minimizeCmd);

    FunctionButton btnHelp("Help");
    btnHelp.setCommand(&helpCmd);

    // Configure setting window
    FBSettingWindow settingsWindow("System Settings");
    settingsWindow.addFunctionButton(btnMinimize);
    settingsWindow.addFunctionButton(btnHelp);

    // Display window and trigger commands
    settingsWindow.display();

    return 0;
}