# PASF - First-Order Periodic/Aperiodic Separation Filter

This is a real-time signal processing algorithm in C++. It implements the first-order periodic/aperiodic separation filter (PASF) proposed by [2]. The general PASF was proposed in [1], and the definitions, characteristics, and advanced design are described in [3]. The first-order PASF has the following three characteristics.

1. Separation of a signal into quasi-periodic and quasi-aperiodic signals
2. Real-time processing with the simple structure
3. Linearity that enables linear analyses and control

The PASF can be used for harmonic noise elimination and periodic/aperiodic separation control.

[1] Hisayoshi Muramatsu, “Separation and Estimation of Periodic/Aperiodic State,” Automatica, vol. 140, Jun. 2022.
(https://www.sciencedirect.com/science/article/pii/S000510982200108X?via%3Dihub)

[2] Hisayoshi Muramatsu and Seiichiro Katsura, “Periodic/Aperiodic Motion Control Using Periodic/Aperiodic Separation Filter,” IEEE Transactions on Industrial Electronics, vol. 67, no. 9, pp. 7649-7658, Sep. 2020.
(https://ieeexplore.ieee.org/abstract/document/8858034)

[3] Hisayoshi Muramatsu and Seiichiro Katsura, “Separated Periodic/Aperiodic State Feedback Control Using Periodic/Aperiodic Separation Filter Based on Lifting,” Automatica, vol. 101, pp. 458-466, Mar. 2019.
(https://www.sciencedirect.com/science/article/pii/S0005109818306307)

## Example

There is a test program that simulates the real-time signal processing, where the PASF separates the signal including the quasi-periodic signal (constant and harmonics) and quasi-aperiodic signals (white and impulse like noise).

## Licence

[MIT License](https://github.com/HisayoshiMuramatsu/PASF/blob/master/LICENSE) © Hisayoshi Muramatsu
