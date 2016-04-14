# cuScaLAPACK

ScaLAPACKの行列積演算 `pdgemm`, `pzgemm` をGPUで計算するライブラリ．


## 動作確認環境

* 物性研スパコン システムB
  * Intel compiler 16.0.1.150
  * SGI MPT 2.12
  * Cuda 7.0


## ライブラリの生成

適切なモジュールをロードした上で `make` すると，静的ライブラリ `libcuscalapack.a` が作成されます．


## リンク方法

Intel MKLよりも前に `libcuscalapack.a` をリンクして下さい．また，CUDA RuntimeとcuBLASもリンクする必要があります．

### Makefileの例

```Makefile
LDFLAGS = -lcudart -lcublas
LDFLAGS += -lmkl_scalapack_lp64 -lmkl_blacs_sgimpt_lp64 -mkl=parallel -lmpi

mpicxx main.cc libcuscalapack.a ${LDFLAGS}
```


## 1ノード内で複数のGPUを使用する場合

1ノードに複数のMPIプロセスを立ち上げることで，複数のGPUを使用することができます．ただし，その際には `cudaSetDevice` により各プロセスにどのGPUを使用するか指定する必要があります．

```C
int mpirank;
int numdevices;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &mpirank);
cudaError_t errorId = cudaGetDeviceCount(&numdevices);
if (errorId != cudaSuccess) exit(EXIT_FAILURE);
cudaSetDevice( mpirank % numdevices );
```

また， `cuscalapack.h` で宣言された `init_cuscalapack()` を呼び出すことで，上記コードと同じ作業をすることが可能です．

```C
#include "cuscalapack.h"

int main(int argc, char **argv) {
    init_cuscalapack();

    ...
}
```


## 謝辞

cuScaLAPACKは，物性研共同利用スパコンGPGPU移植支援サービスにより開発されました．
