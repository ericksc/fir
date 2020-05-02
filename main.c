#include <stdio.h>

// Un filtro IIR bicuadrático (de segundo orden) en forma directa I tiene la siguiente implementacion

void imprimir(int *output_, int size);

// Para mostrar en pantalla los valores de los arreglos
void imprimir(int *output_, int size){
    for(int x = 0; x< size; x++)
    {
        printf("%d\n", output_[x]);
    }
}


void myfir(
        int *in, int *out, int size, int *firtaps, int numtaps
);

void myfir(int *in, int *out, int size, int *firtaps, int numtaps)
{
    int sampleidx;
    int tapidx;
    int outval;
    for(sampleidx=0; sampleidx<size; sampleidx++)
    {
        outval = 0;
        for(tapidx=0; tapidx<numtaps; tapidx++)
        {
            outval += (in[sampleidx+tapidx]) * (firtaps[tapidx]);
        }
        out[sampleidx] = outval;
    }
}


int main() {
    int b0 = 1;
    int b1 = -2;
    int b2 = -3;

    int firtaps[] = {b0,b1,b2};
    int numtaps = 2;

    int input[] = {128, 0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const int input_size = 8;
    int output[15] = {0};

    // Llamando al flitro iir_biquad. Dados los parametros requeridos
    myfir(input,output, input_size, firtaps, numtaps);

    imprimir(output, 6);
    return 0;
}
