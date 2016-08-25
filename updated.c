/*******************************************************************************
 * PROJECT: IMAGE EDITOR
   DATE: 13th FEB 2016
   FUNCTIONALITY: TO ADD FILTERS ON AN .BMP IMAGE

   last update: 23rd april 2016
   Functionalities Added: updated borders
 *
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include "/home/vishu/pset4/bmp/bmp.h"

#define COLOR_RESET  "\033[0;m"
#define BOLD         "\033[1m"
#define BLACK_TEXT   "\033[30;1m"
#define RED_TEXT     "\033[31;1m"
#define GREEN_TEXT   "\033[32;1m"
#define YELLOW_TEXT  "\033[33;1m"
#define BLUE_TEXT    "\033[34;1m"
#define MAGENTA_TEXT "\033[35;1m"
#define CYAN_TEXT    "\033[36;1m"
#define WHITE_TEXT   "\033[37;1m"
#define BOLD_BLACK_TEXT  	"\033[1m\033[30m"
#define BOLD_RED_TEXT 	        "\033[1m\033[31m"
#define BOLD_GREEN_TEXT 	"\033[1m\033[32m"
#define BOLD_YELLOW_TEXT 	"\033[1m\033[33m"
#define BOLD_BLUE_TEXT	        "\033[1m\033[34m"
#define BOLD_MAGENTA_TEXT	"\033[1m\033[35m"
#define BOLD_CYAN_TEXT 	        "\033[1m\033[36m"
#define BOLD_WHITE_TEXT	        "\033[1m\033[37m"

#define numfilter 7

void startdisplay();
int giverandom(void)
{
	srand(time(NULL));
	int tr=rand()%numfilter;
	return tr;

}
/*funciton to implement the displayed color on the image by changing the suitable RGB values*/
RGBTRIPLE getcolor(RGBTRIPLE triple,int i, int j,int color)
{
	if(color==1)
	{
		if (j%2==0&&i%2==0)
		{
            triple.rgbtRed=0xff;
			triple.rgbtGreen=0xe4;
			triple.rgbtBlue=0xb5;
		}
	}
	if (color==2)
	{
		if (j%2==0 &&i%2==0)
		{
         	triple.rgbtRed=0xcd;
			triple.rgbtGreen=0x5c;
			triple.rgbtBlue=0x5c;
		}
	}
	if(color==3)
	{
		if (j%2==0 &&i%2==0)
		{
            triple.rgbtRed=0x93;
			triple.rgbtGreen=0x70;
			triple.rgbtBlue=0xdb;
		}
	}
	if(color==4)
	{
		if (j%2==0 &&i%2==0)
		{
            triple.rgbtRed=0x00;
			triple.rgbtGreen=0x00;
			triple.rgbtBlue=0x80;
		}
	}
	if(color==5)
	{
		//sharp pink
		if (j%2==0 &&i%2==0)
		{
            triple.rgbtRed=0xff;
			triple.rgbtGreen=0x69;
			triple.rgbtBlue=0xb4;
		}


	}
	if(color==6)
	{
		//soft purple
		if (j%2==0 &&i%2==0)
		{
            triple.rgbtRed=0x94;
			triple.rgbtGreen=0x00;
			triple.rgbtBlue=0xd3;
		}
	}
    if(color==7)
	{
		//CYAN
		if (j%2==0 &&i%2==0)
		{
            triple.rgbtRed=0x00;
			triple.rgbtGreen=0xff;
			triple.rgbtBlue=0xff;
		}

	}
	if(color==8)
	{
		//cadet blue
		if (j%2==0 &&i%2==0)
		{
            triple.rgbtRed=0x5f;
			triple.rgbtGreen=0x9e;
			triple.rgbtBlue=0xa0;
		}
	}
	if(color==9)
	{
		//cream color
		if (j%2==0 && i%2==0)
		{
            triple.rgbtRed=0xff;
			triple.rgbtGreen=0xff;
			triple.rgbtBlue=0xe0;
		}

	}
	if(color==10)
	{
		//gold
		if (j%2==0 && i%2==0)
		{
            triple.rgbtRed=0xff;
			triple.rgbtGreen=0x7d;
			triple.rgbtBlue=0x00;
		}
	}
	if(color==11)
	{
		//Red
		if (j%2==0 &&i%2==0)
		{
            triple.rgbtRed=0xff;
			triple.rgbtGreen=0x00;
			triple.rgbtBlue=0x00;
		}

	}
	return triple;
}



/*
	funciton to show the choices for different colors it is just to display and has no functionality
*/
void showchoices()
{
	fprintf(stdout,BOLD_WHITE_TEXT"PICK A COLOR\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"press 1 Moccasin\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"2 Indian Red\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"4 Navy Blue\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"5 Sharp Pink\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"6 Soft Purple\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"7 Cyan\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"8 Cadet Blue\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"9 Cream\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"10 Gold\n"COLOR_RESET);
	fprintf(stdout,YELLOW_TEXT"11 Red\n"COLOR_RESET);
	//printf("pick a color\n\npress 1 Moccasin \n2 Indian Red\n3 Medium Purple\n4 Navy blue\n");
	//printf("5 Sharp Pink\n6 Soft purple\n7 Cyan \n8 Cadet Blue \n9 Cream \n10 Gold\n11 Red");

}

void enddisplay()//function to display credits in the end.
{

	/*printf("\033[23");
	printf("\033[%d;%dH",0,0);*/
	startdisplay();
	int i=0;
	char*a="The requested filter has been applied..!!\nThe output image is stored in the same folder.\n\t\tThanks for your time :)\nPlease Share Your Valuable Reviews...!! \n\t\tDevelopers \nVINEET GOEL\n\n\nSAURABH JAIN\n\n\nV. ASHISH KUMAR\n\n\nVISHVENDRA SINGH RATHORE\n\nDeveloped under the able guidance of Mr Mrityunjay Singh and Ms Divya Gupta\n\n";
	for(i=0;i<strlen(a);i++)
	{
		if(i<88)
		{
			fprintf(stdout,"\033[36;1m%c\033[0;m",a[i]);
		}
		else if(i<158)
		{
			fprintf(stdout,"\033[35;1m%c\033[0;m",a[i]);
		}
		else if(i<243)
		{
			fprintf(stdout,"\033[1m\033[33m%c\033[0;m",a[i]);
		}

		else
		{

			fprintf(stdout,"\033[1m\033[32m%c\033[0;m",a[i]);
		}


		usleep(40000);
		fflush(stdout);

	}

}

void startdisplay(void)//the function to display the name of the program forever
{
	system("clear");
	fprintf(stdout,BOLD_RED_TEXT"\t\tPIC MAGIX (an image enhancement tool for bitmaps)!!\n\n\n"COLOR_RESET);
	//printf("\t\tChangeIt (an image enhancement tool for bitmaps)!!\n\n\n");
}

void borderchoices()
{
	startdisplay();
	fprintf(stdout,BOLD_WHITE_TEXT"PICK A CHOICE\n"COLOR_RESET);
	fprintf(stdout,BOLD_RED_TEXT"Press 1 for Rectangular Borders\nPress 2 for Circular Borders\nPress 3 for Bordered Edges\n"COLOR_RESET);
}

int main(int argc, char* argv[])
{

	int t=0;
    if (argc != 3)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[1];
    char* outfile = argv[2];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

	int d;

	while (1)
	{
		startdisplay();
		fprintf(stdout,BOLD_BLUE_TEXT"Choose one of the following:\n"COLOR_RESET);
		//printf("Choose one of the following:\n");
		fprintf(stdout,BOLD_GREEN_TEXT"enter 1 for resizing the image\n"COLOR_RESET);
		//printf("enter 1 for resizing the image:\n");
		fprintf(stdout,BOLD_GREEN_TEXT"enter 2 for adding simple filters to the image:\n"COLOR_RESET);
		//printf("enter 2 for adding simple filters to the image:\n");
		fprintf(stdout,BOLD_GREEN_TEXT"enter 3 for special filters:\n"COLOR_RESET);
		//printf("enter 3 for special filters:\n");
		fprintf(stdout,GREEN_TEXT"enter 4 for random filter\n"COLOR_RESET);
		//printf("enter 4 for random filter:\n");
		fprintf(stdout,GREEN_TEXT"enter 5 for Borders\n"COLOR_RESET);

		scanf("%d",&d);
		if(d<1||d>5){
		continue;}
		else
		{
			break;
		}
	}

	if(d!=1){
	// read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    /*if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format!!!\n");
        return 4;
    }*/

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

	float biHeight;
	//float biWidth;
	// iterate over infile's scanlines
	float i,j,k;
	biHeight = abs(bi.biHeight);
	char layout;
	int choice;
	int color,color2,color3,color4,color5;
	if(d==5)
		{

		startdisplay();
		borderchoices();
		scanf("%d",&choice);

		showchoices();
		scanf("%d",&color);


		}

	while(d==2){

		/*printf("\033[23");
		printf("\033[%d;%dH",0,0);*/
		startdisplay();
		fprintf(stdout,BLUE_TEXT"ENTER 1 FOR SINGLE COLOR\n"COLOR_RESET);
		fprintf(stdout,YELLOW_TEXT"ENTER 2 for DOUBLE COLOR\n"COLOR_RESET);
		fprintf(stdout,MAGENTA_TEXT"ENTER 3 for TRIPLE COLOR\n"COLOR_RESET);
		//printf("\n \n \nENTER 1 FOR SINGLE COLOR\nENTER 2 FOR DOUBLE COLOR\nENTER 3 FOR TRIPLE COLOR\n\n");
    		scanf("%d",&t);
		if(!((t==1) || (t==2) || (t==3)))
		{
			printf("INVALID\n\n");
			continue;

		}

		if(t!=1&&d!=5)
		{
			startdisplay();
			fprintf(stdout,YELLOW_TEXT"\nENTER H FOR HORIZONTAL\n"COLOR_RESET);
			fprintf(stdout,YELLOW_TEXT"ENTER V FOR VERTICAL\n"COLOR_RESET);
			fprintf(stdout,YELLOW_TEXT"ENTER D FOR DIAGONAL\n"COLOR_RESET);
    			//printf("\n \n \nENTER H FOR HORIZANTAL\nENTER V FOR VERTICAL\nENTER D FOR DIAGONAL\n");
			getchar();
			scanf("%c",&layout);
			if(layout!='V' && layout!='H' && layout!='D')
			{
				printf("INVALID\n\n\n");
				continue;
			}


			else
			{
				break;
			}
		}

		else
		{
			break;
		}

	}


	int special=0;
	while(d==3)
	{	startdisplay();
		fprintf(stdout,BOLD_YELLOW_TEXT"SPECIAL FILTERS\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 1 FOR LINED FILTER\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 2 FOR RAINBOW CURVES\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 3 FOR CYAN\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 4 FOR NEGATIVE\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 5 FOR BLACK AND WHITE\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 6 FOR RANDOM NOISE\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 7 FOR INTENSITY FILTERS\n"COLOR_RESET);
		fprintf(stdout,CYAN_TEXT"ENTER 8 FOR Concentric Circles\n"COLOR_RESET);
		//fprintf(stdout,CYAN_TEXT"ENTER 9 FOR Modified Symbol\n"COLOR_RESET);
		//printf("\tSPECIAL FILTERS\n");
		//printf("ENTER \n1 for Lined filter.\n2 for Rainbow Curves \n3 for Cyan\n4.for Negative\n5.for Black and White\n6.Random Noise filter\n7.Intensity Filter");
		scanf("%d",&special);
		if(special<=0 || special>8)
		{
			startdisplay();
			printf("Invalid");
			printf("\n Try again");
		}
		else
			break;
	}


	int h=biHeight/2;int m=bi.biWidth/2;
	if(special==8)//ashish
		{	startdisplay();
			printf("choose the first color\n");
			showchoices();
			scanf("%d",&color);
			startdisplay();
			printf("choose the second color\n");
			showchoices();
			scanf("%d",&color2);
			startdisplay();
			printf("choose the third color\n");
			showchoices();
			scanf("%d",&color3);
			startdisplay();
			printf("choose the fourth color\n");
			showchoices();
			scanf("%d",&color4);
			startdisplay();
			printf("choose the fifth color\n");
			showchoices();
			scanf("%d",&color5);
		}
	if(special==9)
		{
			startdisplay();
			printf("choose the first color\n");
			showchoices();
			scanf("%d",&color2);
			startdisplay();
			printf("choose the Second color\n");
			showchoices();
			scanf("%d",&color3);
		}

	if(d==4)
	{
		special=giverandom();
	}

	if(t==1 && layout!='R')
		{
			startdisplay();
			fprintf(stdout,BOLD_GREEN_TEXT"CHOOSE THE FIRST COLOR\n"COLOR_RESET);
			//printf("choose the first color\n");
			showchoices();
			scanf("%d",&color);
		}
	else if(t==2 && layout!='R')
		{
			startdisplay();
			fprintf(stdout,BOLD_GREEN_TEXT"CHOOSE THE FIRST COLOR\n"COLOR_RESET);
			//printf("choose the first color\n");
			showchoices();
			scanf("%d",&color);
			startdisplay();
			fprintf(stdout,BOLD_GREEN_TEXT"CHOOSE THE SECOND COLOR\n"COLOR_RESET);
			//printf("choose the second color\n");
			showchoices();
			scanf("%d",&color2);
		}
	else if(t==3 && layout!='R')
		{	startdisplay();
			fprintf(stdout,BOLD_GREEN_TEXT"CHOOSE THE FIRST COLOR\n"COLOR_RESET);
			//printf("choose the first color\n");
			showchoices();
			scanf("%d",&color);
			startdisplay();
			fprintf(stdout,BOLD_GREEN_TEXT"CHOOSE THE SECOND COLOR\n"COLOR_RESET);
			//printf("choose the second color\n");
			showchoices();
			scanf("%d",&color2);
			startdisplay();
			fprintf(stdout,BOLD_GREEN_TEXT"CHOOSE THE THIRD COLOR\n"COLOR_RESET);
			//printf("choose the third color\n");
			showchoices();
			scanf("%d",&color3);

		}

	//float tem=(biHeight/bi.biWidth);
	//float d=tan(tem);
	for ( i = 0;  i < biHeight && d!=1; i++)
    	{
		//biHeight = abs(bi.biHeight);
	 	// iterate over pixels in scanline
        for ( j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            //	 read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
			if(t==1)
            	{
     				triple=getcolor(triple,i, j,color);
				}
			if(layout=='V'){

		    	if(t==3)
		    	{
		    		if( j<bi.biWidth/3)
            		{
            	       triple=getcolor(triple,i, j,color);
		    	    }

				    else if(j<bi.biWidth*2/3)
				    {
					    triple=getcolor(triple,i, j,color2);
				    }
			   	 else
			    	{
					    triple=getcolor(triple,i, j,color3);
			    	}
				}
            	if(t==2)
            	{
                	if(j<bi.biWidth/2)
            			{
            				triple=getcolor(triple, i,j,color);
        				}

    				else if(j>bi.biWidth/2)
    				{
    					triple=getcolor(triple, i,j,color2);
    				}
           		}
			}
	// for diagonal.
            if(layout=='D'){
				if(t==3)
				{
			    if(i-biHeight/ 3&& j<i-biHeight/3)
	           	{
	            	triple=getcolor(triple,i, j,color);
			    }

				else if(j<i+biHeight*2/3)
				{
					triple=getcolor(triple,i, j,color2);
				}
				else
				{
					triple=getcolor(triple,i, j,color3);
				}
			  	}
	          if(t==2)
	            {
               	if(i<j)
            		{
            			triple=getcolor(triple, i,j,color);
        			}

    			else if(i>j)
    			{
    				triple=getcolor(triple, i,j,color2);
    			}
            }
		}

        //for horizontal
        if(layout=='H'){
		    if(t==3)
		    {
		    	if(i<biHeight/3)
            	{
                   	triple=getcolor(triple,i, j,color);
		        }

			    else if(i<biHeight*2/3)
			    {
				    triple=getcolor(triple,i, j,color2);
			    }
			    else
			    {
				    triple=getcolor(triple,i, j,color3);
			    }
			}
            if(t==2)
            {
                if(i<biHeight/2)
            	{
					triple=getcolor(triple, i,j,color);
        		}
    			else if(i>biHeight/2)
    			{
    				triple=getcolor(triple,i, j,color2);
    			}
            }
		}


		if(special==8)//ashish
		    	{	//if(j%2==0&&i%2==0)
				if(((i-h)*(i-h)+(j-m)*(j-m))<=h*m/5)
            			{

		    	       		triple=getcolor(triple,i,j,color);
							/*riple.rgbtRed=0xff;
							triple.rgbtGreen=0xe4;
							triple.rgbtBlue=0xb5;*/


		    	    	}

				else if(((i-h)*(i-h)+(j-m)*(j-m))<=h*m/2)
            			{
		         			/*triple.rgbtRed=0xcd;
							triple.rgbtGreen=0x5c;
							triple.rgbtBlue=0x5c;*/
		    	       		triple=getcolor(triple,i,j,color2);

		    	    	}
				else if(((i-h)*(i-h)+(j-m)*(j-m))<h*m)
            			{
            	       		/*triple.rgbtRed=0x93;
							triple.rgbtGreen=0x70;
							triple.rgbtBlue=0xdb;*/

		    	       		triple=getcolor(triple,i,j,color3);

		    	    	}
				else if(((i-h)*(i-h)+(j-m)*(j-m))<h*m*2)
            			{
            				/*triple.rgbtRed=0x00;
							triple.rgbtGreen=0x00;
							triple.rgbtBlue=0x80;*/

		    	       		triple=getcolor(triple,i,j,color4);

		    	    	}

			   	else
		    		{	    /*triple.rgbtRed=0xff;
							triple.rgbtGreen=0x69;
							triple.rgbtBlue=0xb4;*/

					   		triple=getcolor(triple,i,j,color5);
			    	}

			}
		//for special filters
		if(special!=0)
		{

			//printf("%d\n\n",tr);
			//float c;
			if(j!=0)
			{
				//float x=i/j;
				//c=tan(x);
			}

			if(special==1)

			{
				if(i<bi.biWidth*sin(j))
            	{
                   	if ((int)j%2==0 &&(int)i%2==0)
					{
		            	triple.rgbtGreen=0xf0;
				     }
				}

			    /*else if(i<100*sin(j))
			    {
				    triple.rgbtRed=0xf0;
			    }*/
			    else
			    {
				    triple.rgbtBlue=0xf0;
			    }
			}

			if(special==2&&(int)i%2==0&&(int)j%2==0)

				{
				if((i*j*10)<(d*bi.biWidth*biHeight/4))
            	{
                   	triple.rgbtRed=0x19;
		            triple.rgbtGreen=0x19;
		            triple.rgbtBlue=0x70;
		        }
				else if((i*j*10)<(d*bi.biWidth*biHeight))
            	{
                   	triple.rgbtRed=0x00;
		            triple.rgbtGreen=0x64;
		            triple.rgbtBlue=0x00;
		        }

			    else if((i*j*10)<(d*bi.biWidth*biHeight)*2)
			    {
				    triple.rgbtRed=0xff;
					triple.rgbtBlue=0x00;
					triple.rgbtBlue=0x00;
			    }

			    else
			    {

				    triple.rgbtRed=0xff;
					triple.rgbtBlue=0xe4;
					triple.rgbtBlue=0xe1;

			    }

			}

			if(special==3) // implementation for cyan by VSR
			{
				triple.rgbtRed=0xff-triple.rgbtRed;
				triple.rgbtGreen=triple.rgbtGreen;
				triple.rgbtBlue=triple.rgbtBlue;
			}
			if(special==4)//implementation for negative by VSR
			{
				triple.rgbtRed=0xff-triple.rgbtRed;
				triple.rgbtGreen=0xff-triple.rgbtGreen;
				triple.rgbtBlue=0xff-triple.rgbtBlue;
			}
			if(special==5)//implementation for black and white by MK
			{
				int dec1=triple.rgbtRed;
				int dec2=triple.rgbtGreen;
				int dec3=triple.rgbtBlue;
				triple.rgbtRed=(dec1+dec2+dec3)/3;
				triple.rgbtGreen=(dec1+dec2+dec3)/3;
				triple.rgbtBlue=(dec1+dec2+dec3)/3;
			}
			if(special==6)//sign filter by MK
			{
				float _1=bi.biWidth/2-j;
				float power=pow(_1,2);
				if(sin((i*i)-(power)) <(sin(bi.biWidth/2))){

				//triple.rgbtRed=0xf0;
				triple.rgbtGreen=0x0f;
				triple.rgbtBlue=0xff;

			}
			double c=105;
			if(special==7)//intensity filter implemented by VSR
			{
				triple.rgbtRed=(c*log(1+triple.rgbtRed));
				triple.rgbtGreen=(c*log(1+triple.rgbtGreen));
				triple.rgbtBlue=(c*log(1+triple.rgbtGreen));
			}



			if(special==9)//ashish
	 		{	//int z= pow(i,2/3);
				//if(j%2==0&&i%2==0)

				if( j<=i)
           			{
        	       			//triple.rgbtRed=0xff;
	    		       		triple=getcolor(triple,i,j,color);
                	    	        //triple.rgbtBlue=0xff;
		    	    	}


			   	 else if(j>=i+(bi.biWidth-biHeight))
			    	{		triple=getcolor(triple,i,j,color);
					    //triple.rgbtRed=0xf0;
			    	}
				else
				{		triple=getcolor(triple,i,j,color2);
						//triple.rgbtGreen=0xf0;
				}
				if((biHeight-i)>=j)
            			{

	    			        //triple.rgbtRed=0xf0;
                		        triple=getcolor(triple,i,j,color);
		       		}


				 else if((bi.biWidth-j<=i))
		      		 {		triple=getcolor(triple,i,j,color);
					    //triple.rgbtRed=0xf0;
	    			 }
				else
				{	triple=getcolor(triple,i,j,color2);
					//triple.rgbtGreen=0xf0;
				}

		}
			}

		}
		if(d==5 )
		{

			if(choice==1 && i<biHeight/10||i>biHeight*0.9||j<bi.biWidth/10||j>bi.biWidth*0.9)
			{
				triple=getcolor(triple,i,j,color);
			}
			else if(choice==2)
			{
				if(((i-h)*(i-h)+(j-m)*(j-m))<=h*m/5)
            			{

		    	       		//triple=getcolor(triple,i,j,color);
							/*riple.rgbtRed=0xff;
							triple.rgbtGreen=0xe4;
							triple.rgbtBlue=0xb5;*/


		    	    	}

				else if(((i-h)*(i-h)+(j-m)*(j-m))<=h*m/2)
            			{
		         			/*triple.rgbtRed=0xcd;
							triple.rgbtGreen=0x5c;
							triple.rgbtBlue=0x5c;*/
		    	       		//triple=getcolor(triple,i,j,color2);

		    	    	}
				else if(((i-h)*(i-h)+(j-m)*(j-m))<h*m*1.99999)
            			{
            	       		/*triple.rgbtRed=0x93;
							triple.rgbtGreen=0x70;
							triple.rgbtBlue=0xdb;*/

		    	       		triple=getcolor(triple,i,j,color);

		    	    	}

			}
			else if(choice==3 && (j<bi.biWidth/5 && (i<biHeight/5||i>biHeight*0.8)||j>bi.biWidth*0.8&&(i<biHeight/5||i>biHeight*0.8)))
			{
				triple=getcolor(triple,i,j,color);
			}

		}



            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back
        for (k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }}
	else if(d==1)
	{	int n;
		while(1){
			fprintf(stdout,BOLD_CYAN_TEXT"ENTER THE FACTOR BETWEEN 1 to 20\n"COLOR_RESET);
			//printf("Enter the factor between 1 to 20:");
			scanf("%d",&n);
			if(n<=0||n>20)
			{
				fprintf(stdout,BOLD_CYAN_TEXT"INVALID NUMBER PLEASE TRY AGAIN\n"COLOR_RESET);
				//printf("Invalid number please corporate!!\n Try again");
				continue;
			}
			else
			{
				break;
			}


		}
		BITMAPFILEHEADER bf;
    	fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    	// read infile's BITMAPINFOHEADER
    	BITMAPINFOHEADER bi;
    	fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    	// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    	/*if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        	bi.biBitCount != 24 || bi.biCompression != 0)
    	{
        	fclose(outptr);
        	fclose(inptr);
        	fprintf(stderr, "Unsupported file format.\n");
        	return 4;
    	}*/

		BITMAPFILEHEADER bfout;
		BITMAPINFOHEADER biout;
		bfout=bf;
		biout=bi;
		biout.biWidth=n*bi.biWidth;
		biout.biHeight=n*bi.biHeight;
		int padding1 =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
		int padding2 =  (4 - (biout.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

		biout.biSizeImage=biout.biHeight*biout.biWidth*sizeof(RGBTRIPLE)+padding2*abs(biout.biHeight);
		bfout.bfSize = 54 + biout.biSizeImage;
		// write outfile's BITMAPFILEHEADER
    	fwrite(&bfout, sizeof(BITMAPFILEHEADER), 1, outptr);

    	// write outfile's BITMAPINFOHEADER
    	fwrite(&biout, sizeof(BITMAPINFOHEADER), 1, outptr);

    	// determine padding for scanlines


		float biHeight;
		//float biWidth;
		// iterate over infile's scanlines
		float i,j,k,l;
		biHeight = abs(bi.biHeight);
		for ( i = 0;  i < biHeight; i++)
    	{

		 // iterate over pixels in scanline
		for(l=0;l<n;l++){
		for ( j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            //	 read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
			for(k=0;k<n;k++){
            fwrite(&triple, sizeof(RGBTRIPLE),1, outptr);}


        }
		fseek(inptr, padding1, SEEK_CUR);
		for (k = 0; k < padding2; k++)
        {
            fputc(0x00, outptr);
        }
		fseek(inptr, -(bi.biWidth*3+padding1), SEEK_CUR);}

		fseek(inptr, (bi.biWidth*3+padding1), SEEK_CUR);


    }

	}

	enddisplay();

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;
}
