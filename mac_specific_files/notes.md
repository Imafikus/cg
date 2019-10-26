# Including GLUT 

use `#include <GLUT/glut.h>`instead of `#include <GL/glut.h>`

# Silencing warnings

If you are building on macOS you'll have bunch of depreciation warnings, in order to avoid them just define `GL_SILENCE_DEPRECATION` in the beginning of the file, like this:
```
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

static void on_display(void);

Your code here
...

```