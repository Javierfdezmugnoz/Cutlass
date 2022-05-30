#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi()
#include <math.h>   // abs()

typedef float    float32_t;
typedef double   float64_t;
typedef void     void_t;
typedef __uint32_t uint32_t;
typedef _Bool    bool;

#define DIM_M 64
#define DIM_N 6
#define DIM_K 8
#define NAME "01_TECH_XOR_EXTERNAL"

uint32_t main (void_t){
    char buffer[1000000];
    char *buffer_aux;
    char str_fi_idx_aux[100u] = "_"NAME"_idx_DC.csv";
    char str_path_aux[100u] = "/home/javifdez/git_repository/Cutlass/exp_results/opt_O3/dc/";
    char str_fi_idx_1[100u];
    char str_fi_idx_4[100u];
    char str_path_1[150u];
    char str_path_4[150u];

    uint32_t max_val = (DIM_M>DIM_N) ? DIM_M : DIM_N;
    uint32_t min_val = (DIM_M<DIM_N) ? DIM_M : DIM_N;
    snprintf(str_fi_idx_1, 100,"%d_%d_%d",max_val,max_val,DIM_K);
    snprintf(str_path_1, 150,"%s%s/%s%s",str_path_aux,str_fi_idx_1,str_fi_idx_1,str_fi_idx_aux);

    snprintf(str_fi_idx_4, 100,"%d_%d_%d",min_val,min_val,DIM_K);
    snprintf(str_path_4, 150,"%s%s/%s%s",str_path_aux,str_fi_idx_4,str_fi_idx_4,str_fi_idx_aux);

    printf("matrix_1: %s\nmatrix_2: %s\n",str_fi_idx_1,str_fi_idx_4);
    printf("path1: %s\npath2: %s\n",str_path_1,str_path_4);

    bool b_array_detected_fi_B1[DIM_M*DIM_K*32];
    bool b_array_detected_fi_A1[DIM_M*DIM_K*32];

    bool b_array_detected_fi_B4[DIM_N*DIM_K*32];
    bool b_array_detected_fi_A4[DIM_N*DIM_K*32];



    FILE *p_file_idx_1 = fopen(str_path_1, "r+");
    if (p_file_idx_1 == NULL) 
    {
        printf("Could not open file str_path_4.txt\n");
        return (0u); 
    }

    // Move the pointer to the beggining of the file
    fseek(p_file_idx_1,0,SEEK_SET);
    fscanf(p_file_idx_1,"%[^\n] ",buffer);
    buffer_aux = strtok(buffer,"{");
    for(uint32_t idx_num_it=0;idx_num_it<(max_val*DIM_K*32);idx_num_it++)
    {
        buffer_aux = strtok(NULL,",");
        b_array_detected_fi_B1[idx_num_it]=atoi(buffer_aux);
    }
    fscanf(p_file_idx_1,"%[^\n] ",buffer);
    buffer_aux = strtok(buffer,"{");
    for(uint32_t idx_num_it=0;idx_num_it<(max_val*DIM_K*32);idx_num_it++)
    {
        buffer_aux = strtok(NULL,",");
        b_array_detected_fi_A1[idx_num_it]=atoi(buffer_aux);
    }
    fclose(p_file_idx_1);


    FILE *p_file_idx_4 = fopen(str_path_4, "r+");
    if (p_file_idx_4 == NULL) 
    {
        printf("Could not open file str_path_4.txt\n");
        return (0u); 
    }

    // Move the pointer to the beggining of the file
    fseek(p_file_idx_4,0,SEEK_SET);
    printf("\nVal b4:\n");
    fscanf(p_file_idx_4,"%[^\n] ",buffer);
    buffer_aux = strtok(buffer,"{");
    for(uint32_t idx_num_it=0;idx_num_it<(min_val*DIM_K*32);idx_num_it++)
    {
        buffer_aux = strtok(NULL,",");
        b_array_detected_fi_B4[idx_num_it]=atoi(buffer_aux);
    }
    fscanf(p_file_idx_4,"%[^\n] ",buffer);
    printf("\nVal A4:\n");
    buffer_aux = strtok(buffer,"{");
    for(uint32_t idx_num_it=0;idx_num_it<(min_val*DIM_K*32);idx_num_it++)
    {
        buffer_aux = strtok(NULL,",");
        b_array_detected_fi_A4[idx_num_it]=atoi(buffer_aux);
    }
    fclose(p_file_idx_4);

    return 0;
}