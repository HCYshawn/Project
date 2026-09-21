class BrowserHistory
{
public:
    BrowserHistory(string homepage)
        : _data{homepage},
          _cur(0)
    {
    }

    void visit(string url)
    {
        _data.resize(_cur + 1);
        _data.push_back(url);
        _cur = _data.size() - 1;
    }

    string back(int steps)
    {
        if (steps > _cur)
            _cur = 0;
        else
            _cur -= steps;
        return _data[_cur];
    }

    string forward(int steps)
    {
        if (steps > _data.size() - _cur - 1)
        {
            _cur = _data.size() - 1;
        }
        else
            _cur += steps;
        return _data[_cur];
    }

private:
    vector<string> _data;
    size_t _cur = 0;
};
