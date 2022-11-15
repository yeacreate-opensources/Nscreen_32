#ifndef IO_SERVICE_H
#define IO_SERVICE_H

class io_service
{
private:


public:
  io_service();
  ~io_service();


  /* =============================icache functions============================= */
  void ICACHE_FLASH_ATTR setup();
  // void ICACHE_FLASH_ATTR loop();
  /* ============================end icache functions========================== */
};
#endif