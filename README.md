# PASF - First-Order Periodic/Aperiodic Separation Filter

This is a real-time signal processing algorithm in C++. It implements the filter proposed by [1] and [2]. The first-order periodic/aperiodic separation filter (PASF) has the following three characteristics.

1. Separation of a signal into periodic and aperiodic signals
2. Real-time processing caused by the simple structure
3. Linearity which enables linear analyses and control

The PASF can be used for control engineering, which realizes periodic/aperiodic state feedback control and periodic/aperiodic motion control.

[1] Hisayoshi Muramatsu and Seiichiro Katsura, “Periodic/Aperiodic Motion Control Using Periodic/Aperiodic Separation Filter,” IEEE Transactions on Industrial Electronics, Early Access.
(https://ieeexplore.ieee.org/abstract/document/8858034)

[2] Hisayoshi Muramatsu and Seiichiro Katsura, “Separated Periodic/Aperiodic State Feedback Control Using Periodic/Aperiodic Separation Filter Based on Lifting,” Automatica, vol. 101, pp. 458-466, Mar. 2019.
(https://www.sciencedirect.com/science/article/pii/S0005109818306307)

## Example

There is a test program that simulates the real-time signal processing, where the PASF separates a signal including a periodic signal (constant and harmonic elements) and aperiodic signals (white and impulse noise).

## Licence

[MIT License](https://github.com/HisayoshiMuramatsu/PASF/blob/master/LICENSE) © Hisayoshi Muramatsu
