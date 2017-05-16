#include "jpegilib.h"


#define JPEG_QUALITY 100 //ͼƬ����  
  
int savejpg(uchar *pdata, char *jpg_file, int width, int height)  
{  //�ֱ�ΪRGB���ݣ�Ҫ�����jpg�ļ�����ͼƬ����  
    int depth = 3;  
    JSAMPROW row_pointer[1];//ָ��һ��ͼ�����ݵ�ָ��  
    struct jpeg_compress_struct cinfo;  
    struct jpeg_error_mgr jerr;  
    FILE *outfile;  
  
    cinfo.err = jpeg_std_error(&jerr);//Ҫ���ȳ�ʼ��������Ϣ  
    //* Now we can initialize the JPEG compression object.  
    jpeg_create_compress(&cinfo);  
  
    if ((outfile = fopen(jpg_file, "wb")) == NULL)  
    {  
        fprintf(stderr, "can't open %s\n", jpg_file);  
        return -1;  
    }  
    jpeg_stdio_dest(&cinfo, outfile);  
  
    cinfo.image_width = width;             //* image width and height, in pixels  
    cinfo.image_height = height;  
    cinfo.input_components = depth;    //* # of color components per pixel  
    cinfo.in_color_space = JCS_RGB;     //* colorspace of input image  
    jpeg_set_defaults(&cinfo);  
  
    jpeg_set_quality(&cinfo, JPEG_QUALITY, TRUE ); //* limit to baseline-JPEG values  
    jpeg_start_compress(&cinfo, TRUE);  
  
    int row_stride = width * 3;  
    while (cinfo.next_scanline < cinfo.image_height)  
           {  
            row_pointer[0] = (JSAMPROW)(pdata + cinfo.next_scanline * row_stride);//һ��һ�����ݵĴ���jpegΪ������ݸ�ʽ  
            jpeg_write_scanlines(&cinfo, row_pointer, 1);  
        }  
  
    jpeg_finish_compress(&cinfo);  
    jpeg_destroy_compress(&cinfo);//�⼸���������ǹ̶�����  
    fclose(outfile);  
  
    return 0;  
}  