#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ת������
class Command;
class WindowHandler;
class HelpHandler;

// ����������
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

// ���������
class WindowHandler
{
public:
    void minimize()
    {
        cout << "������С��." << endl;
    }
};

// ���������
class HelpHandler
{
public:
    void display()
    {
        cout << "��ʾ������Ϣ." << endl;
    }
};

// ����������
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

// ����������
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

// ���������
class FunctionButton
{
    string name;      // ���ܼ�����
    Command *command; // ά��һ������������������

public:
    explicit FunctionButton(const string &btnName) : name(btnName), command(nullptr) {}

    string getName() const { return name; }

    void setCommand(Command *cmd)
    {
        command = cmd;
    }

    void onClick() // ������������execute()����
    {
        if (command)
            command->execute();
    }
};

// �����ܼ����á�������
class FBSettingWindow
{
    string title;                           // ���ڱ���
    vector<FunctionButton> functionButtons; // ���ܼ�����

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
            cout << "[" << btn.getName() << "] "; // ��ʾ���ܼ�����
            btn.onClick();                        // ���ù��ܼ���Ӧ����������execute()����
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