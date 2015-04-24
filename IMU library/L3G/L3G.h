#ifndef L3G_h
#define L3G_h

#include <Arduino.h> // for byte data type

class L3G
{
  public:
    template <typename T> struct vector
    {
      T x, y, z;
    };

    enum deviceType { device_D20H, device_auto };
    enum sa0State { sa0_low, sa0_high, sa0_auto };

    // register addresses
    enum regAddr
    {
       WHO_AM_I       = 0x0F,

       CTRL1          = 0x20, // D20H
       CTRL2          = 0x21, // D20H
       CTRL3          = 0x22, // D20H
       CTRL4          = 0x23, // D20H
       CTRL5          = 0x24, // D20H
       REFERENCE      = 0x25,
       OUT_TEMP       = 0x26,
       STATUS         = 0x27, // D20H

       OUT_X_L        = 0x28,
       OUT_X_H        = 0x29,
       OUT_Y_L        = 0x2A,
       OUT_Y_H        = 0x2B,
       OUT_Z_L        = 0x2C,
       OUT_Z_H        = 0x2D,

       FIFO_CTRL      = 0x2E, // D20H
       FIFO_SRC       = 0x2F, // D20H

       IG_CFG         = 0x30, // D20H
       IG_SRC         = 0x31, // D20H
       IG_THS_XH      = 0x32, // D20H
       IG_THS_XL      = 0x33, // D20H
       IG_THS_YH      = 0x34, // D20H
       IG_THS_YL      = 0x35, // D20H
       IG_THS_ZH      = 0x36, // D20H
       IG_THS_ZL      = 0x37, // D20H
       IG_DURATION    = 0x38, // D20H
       LOW_ODR        = 0x39  // D20H
    };

    vector<int16_t> g; // gyro angular velocity readings

    byte last_status; // status of last I2C transmission

    L3G(void);

    bool init(deviceType device = device_auto, sa0State sa0 = sa0_auto);
    deviceType getDeviceType(void) { return _device; }

    void enableDefault(void);

    void writeReg(byte reg, byte value);
    byte readReg(byte reg);

    void read(void);

    void setTimeout(unsigned int timeout);
    unsigned int getTimeout(void);
    bool timeoutOccurred(void);

    // vector functions
    template <typename Ta, typename Tb, typename To> static void vector_cross(const vector<Ta> *a, const vector<Tb> *b, vector<To> *out);
    template <typename Ta, typename Tb> static float vector_dot(const vector<Ta> *a, const vector<Tb> *b);
    static void vector_normalize(vector<float> *a);

  private:
      deviceType _device; // chip type (D20H)
      byte address;

      unsigned int io_timeout;
      bool did_timeout;

      int testReg(byte address, regAddr reg);
};

template <typename Ta, typename Tb, typename To> void L3G::vector_cross(const vector<Ta> *a, const vector<Tb> *b, vector<To> *out)
{
  out->x = (a->y * b->z) - (a->z * b->y);
  out->y = (a->z * b->x) - (a->x * b->z);
  out->z = (a->x * b->y) - (a->y * b->x);
}

template <typename Ta, typename Tb> float L3G::vector_dot(const vector<Ta> *a, const vector<Tb> *b)
{
  return (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
}

#endif



