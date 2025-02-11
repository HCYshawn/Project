#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ǰ������
class ChessmanMemento;

// �����ࣨOriginator��
class Chessman
{
private:
    string label;
    int x;
    int y;

public:
    Chessman(const string &label, int x, int y)
        : label(label), x(x), y(y) {}

    // ���浱ǰ״̬������¼
    ChessmanMemento save();

    // �ӱ���¼�ָ�״̬
    void restore(const ChessmanMemento &memento);

    // Getter��Setter
    string getLabel() const { return label; }
    void setLabel(const string &label) { this->label = label; }
    int getX() const { return x; }
    void setX(int x) { this->x = x; }
    int getY() const { return y; }
    void setY(int y) { this->y = y; }
};

// ���ӱ���¼�ࣨMemento��
class ChessmanMemento
{
private:
    string label;
    int x;
    int y;

    // ������Ԫ�࣬����Chessman����˽�г�Ա
    friend class Chessman;

    // ���캯��˽�л���ȷ��ֻ��Chessman���Դ�������¼
    ChessmanMemento(const string &label, int x, int y)
        : label(label), x(x), y(y) {}

public:
    // Getter������Caretaker���Ի�ȡ״̬�����޸ģ�
    string getLabel() const { return label; }
    int getX() const { return x; }
    int getY() const { return y; }
};

// Chessman��save��restoreʵ��
ChessmanMemento Chessman::save()
{
    return ChessmanMemento(label, x, y); // ����˽�й��캯��
}

void Chessman::restore(const ChessmanMemento &memento)
{
    label = memento.label;
    x = memento.x;
    y = memento.y;
}

// ����¼�����ߣ�Caretaker��
class MementoCaretaker
{
private:
    vector<ChessmanMemento> mementoList; // �洢����¼����

public:
    // ��ȡָ��λ�õı���¼
    ChessmanMemento getMemento(int index) const
    {
        if (index >= 0 && index < mementoList.size())
        {
            return mementoList[index];
        }
        throw out_of_range("��Ч������");
    }

    // ����µı���¼
    void setMemento(const ChessmanMemento &memento)
    {
        mementoList.push_back(memento);
    }
};

int main()
{
    // �������Ӳ����ó�ʼ״̬
    Chessman chessman("��", 1, 2);
    MementoCaretaker caretaker;

    // �����ʼ״̬
    caretaker.setMemento(chessman.save());      // ����״̬
    cout << "��ʼ״̬: " << chessman.getLabel() // ���״̬
         << " (" << chessman.getX() << ", " << chessman.getY() << ")\n";

    // �޸�����״̬
    chessman.setX(3);
    chessman.setY(4);
    cout << "�޸ĺ�״̬: " << chessman.getLabel()
         << " (" << chessman.getX() << ", " << chessman.getY() << ")\n";

    // �ӱ���¼�ָ�״̬
    chessman.restore(caretaker.getMemento(0));
    cout << "�ָ���״̬: " << chessman.getLabel()
         << " (" << chessman.getX() << ", " << chessman.getY() << ")\n";

    return 0;
}