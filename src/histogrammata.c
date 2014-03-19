/*
 ============================================================================
 Name        : histogrammata.c
 Author      : mel--mel
 Version     :
 Copyright   : (c) mel--mel 2014
 Description : Histogram equalization + maching
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

int main(void) {

	unsigned char* image;
	unsigned width, height, x, y, error;
	int pos, input_channels;
	int pixel_values[256][256];

	input_channels = 4;

	error = lodepng_decode32_file(&image, &width, &height, "LenaDark.png");
	if(error) {
		printf("error %u: %s\n", error, lodepng_error_text(error));
	}
	else{
		printf("Image successfully open!\n");
	}

	printf("\nwidth = %u\n", width);
	printf("height = %u\n\n\n", height);
/*
	//printf("RGB values are:\n");

	for (y=0; y < 2; y++) { // --> first 2 rows
	//for (y=0; y < height; y++) {
	//	for (x=0; x < 2; x++) { //--> first 2 columns
		for (x=0; x < width; x++) {
		    printf("|");
		    for (pos=0; pos < 3; pos++) {
		        printf("%d ", image[y*width*input_channels + x*input_channels + pos]);
		        }
		    printf("|");
		    }
		 printf("\n");
		 }
*/

	for (y=0; y < height; y++) {
		for (x=0; x < width; x++) {
			pixel_values[x][y] = image[y*width*input_channels + x*input_channels];
			    }
			 }

	for (y=0; y < height; y++) {
		for (x=0; x < width; x++) {
			printf("|%d|  ", pixel_values[x][y]);
			}
		printf("\n");
		}

	/*for (y=100; y < 150; y++) { // --> first 2 rows
		//for (y=0; y < height; y++) {
			for (x=100; x < 150; x++) { //--> first 2 columns
			//for (x=0; x < width; x++) {
			    for (pos=0; pos < 3; pos++) {
			        image[y*width*input_channels + x*input_channels + pos] = 255;
			        }
			    }
			 }

	for (y=150; y < 180; y++) { // --> first 2 rows
			//for (y=0; y < height; y++) {
				for (x = 200; x < 250; x++) { //--> first 2 columns
				//for (x=0; x < width; x++) {
				    for (pos=1; pos < 3; pos++) {
				        image[y*width*input_channels + x*input_channels + pos] = 0;
				        }
				    }
				 } */

	/*Encode the image*/
	 /* error = lodepng_encode32_file("test_img.png", image, width, height); */

	  /*if there's an error, display it*/
	  if(error) printf("error %u: %s\n", error, lodepng_error_text(error));

	free(image);

	return EXIT_SUCCESS;
}
