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

void print_RGB_values(unsigned width, unsigned height, int input_channels, unsigned char *image){

	int x, y, pos;

	printf("RGB values are:\n");

	//for (y=0; y < 2; y++) { // --> first 2 rows
	for (y=0; y < height; y++) {
		//for (x=0; x < 2; x++) { //--> first 2 columns
		for (x=0; x < width; x++) {
			printf("|");
			for (pos=0; pos < 3; pos++) {
			    printf("%d ", image[y*width*input_channels + x*input_channels + pos]);
			    }
			printf("|");
			}
	    printf("\n");
		}
}

void make_grayscale_pixel_values_array(unsigned width, unsigned height, int input_channels, unsigned char *image, int pixel_values[width][height]){
	int x, y;

	for (y=0; y < height; y++) {
			for (x=0; x < width; x++) {
				pixel_values[x][y] = image[y*width*input_channels + x*input_channels];
				}
		    }
}

void print_pixel_values(unsigned width, unsigned height, int pixel_values[width][height]){
	int x, y;

	for (y=0; y < height; y++) {
			for (x=0; x < width; x++) {
				printf("|%d|  ", pixel_values[x][y]);
				}
			printf("\n");
			}
}

void change_RGB_values(unsigned width, unsigned height, int input_channels, unsigned char *image){
	int x, y, pos;

	for (y=100; y < 150; y++) { // --> first 2 rows
			//for (y=0; y < height; y++) {
				for (x=100; x < 150; x++) { //--> first 2 columns
				//for (x=0; x < width; x++) {
				    for (pos=0; pos < 3; pos++) {
				        image[y*width*input_channels + x*input_channels + pos] = 255;
				        }
				    }
				 }
}

int main(void) {

	unsigned char* image;//, *new_image;
	unsigned width, height, error;
	//int pos;
	int input_channels;
	int pixel_values[256][256];


	/*open image + handle error*/
	input_channels = 4;

	error = lodepng_decode32_file(&image, &width, &height, "LenaDark.png");
	if(error) {
		printf("error %u: %s\n", error, lodepng_error_text(error));}
	else{
		printf("Image successfully open!\n");}

	/*print width + height*/
	printf("\nwidth = %u\n", width);
	printf("height = %u\n\n\n", height);


	/*put pixel values in an array*/
	make_grayscale_pixel_values_array(width, height, input_channels, image, pixel_values);

    /*print pixel values*/
	//print_pixel_values(width, height, pixel_values);

	/*count different pixel values*/
	//TO DO

	/*change image*/
	change_RGB_values(width, height, input_channels, image);

	/*print RGB values*/
	//print_RGB_values(width, height, input_channels, image);


	 /*Encode the image + error handling*/
	 error = lodepng_encode32_file("img_out.png", image, width, height);
	 if(error){
		 printf("error %u: %s\n", error, lodepng_error_text(error));}
	 else{
		 printf("Image successfully saved!\n");}

	free(image);

	return EXIT_SUCCESS;
}
