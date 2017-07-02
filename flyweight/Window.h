#pragma once

#include "IBuffer.h"
#include "Viewport.h"
#include <memory>
#include <vector>

struct Window
{
  int width, height;

  std::vector<std::shared_ptr<IBuffer>> buffers;
  std::vector<std::shared_ptr<Viewport>> viewports;
  static void ResizeFunction(int, int);
  
  Window(std::string title, int width, int height);

  void DrawEverything();
  void Show();
  std::pair<int, int> size() const;

  ~Window();

  // used to get around the callback stupidity with C APIs
  static Window* self;
};
