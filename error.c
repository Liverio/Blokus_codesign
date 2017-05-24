#include "error.h"

void error(signed char error){
    switch (error){
        case -1: xil_printf("TILE ON OCCUPIED SQUARE\n");
                 break;
        case -2: xil_printf("TILE OUT OF BOARD\n");
                 break;
        case -3: xil_printf("BORDER TO BORDER CONTACT\n");
                 break;
        case -4: xil_printf("NO VERTEX FOUND\n");
                 break;
        case -5: xil_printf("INSUFFICIENT OVERLAP\n");
                 break;
        case -6: xil_printf("WRONG COLOR\n");
                 break;
    }
}
