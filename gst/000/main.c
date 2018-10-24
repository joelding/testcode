#include <gst/gst.h>
#include <glib.h>

int main(int argc, char *argv[])
{
	gst_init(&argc, &argv);

	g_print("Hello gstreamer %s\n", gst_version_string());

	return 0;
}

