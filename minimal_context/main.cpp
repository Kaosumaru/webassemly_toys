extern "C"
{
    void jsLog(const char *, unsigned int);
    void jsFillRect(int, int, int, int);
    void jsClearRect(int, int, int, int);
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

namespace
{
    bool keys[256] = {0};
}

//exports
extern "C"
{
    void runCallback(void (*callback)()) { callback(); }

    void onKey(int key, bool pressed)
    {
        if (key > 255) return;
        keys[key] = pressed;
    }

    void onFrame(float dt)
    {

        static float posX = 0.0f, posY = 0.0f;
        jsClearRect(posX,posY,100,100);

        float speed = 100.0f;
        if(keys[37]) posX -= speed * dt;
        if(keys[39]) posX += speed * dt;

        if(keys[38]) posY -= speed * dt;
        if(keys[40]) posY += speed * dt;

        jsFillRect(posX,posY,100,100);
    }

    int main()
    {
        consoleLog("Hello world");
        return 0;
    }
}
