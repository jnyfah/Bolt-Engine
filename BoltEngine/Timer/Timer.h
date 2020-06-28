#ifndef TIMER_H
#define TIMER_H

const int TARGET_FPS = 60;
const float TARGET_DELTA_TIME = 1.5f;
class Timer
{
    public:
        inline  static Timer *Get_Instance()
        {
            if(Instance == nullptr)
            {
                Instance = new Timer;
            }

            return Instance;
        }

        void Tick();
        float Get_deltatime()
        {
            return m_deltatime;
        }




    private:
         Timer(){}
         static Timer *Instance;
         float m_deltatime;
         float lasttime;
};

#endif // TIMER_H
