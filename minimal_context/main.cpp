extern "C"
{
    void jsLog(const char *, unsigned int);
}

unsigned int strlen(const char *str)
{
    unsigned int len;
    for (len = 0; str[len]; (len)++);
    return len;
}

void consoleLog(const char *str)
{
    auto size = strlen(str);
    jsLog(str, size);
}

extern "C" int doubler(int x)
{
    consoleLog("Hello world");
    return 2 * x;
}
