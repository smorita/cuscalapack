# cuScaLAPACK

ScaLAPACKの行列積演算 `pdgemm`, `pzgemm` をGPUで計算するライブラリ．


## 動作確認環境

* 物性研スパコン システムB
  * Intel compiler 16.0.1.150
  * SGI MPT 2.12
  * Cuda 7.0


## ライブラリの生成

適切なモジュールをロードした上で `make` すると，静的ライブラリ `libcuscalapack.a` が作成されます．


## 利用方法

Intel MKLよりも前に `libcuscalapack.a` をリンクして下さい．また，CUDA RuntimeとcuBLASもリンクする必要があります．

### 例

```Makefile
LDFLAGS = -lcudart -lcublas
LDFLAGS += -lmkl_scalapack_lp64 -lmkl_blacs_sgimpt_lp64 -mkl=parallel -lmpi

mpicxx main.cc libcuscalapack.a ${LDFLAGS}
```


## 謝辞

cuScaLAPACKは，物性研共同利用スパコンGPGPU移植支援サービスにより開発されました．
