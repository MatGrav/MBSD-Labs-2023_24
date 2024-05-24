/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_arduino_data.c
 *
 * Code generated for Simulink model 'controller_arduino'.
 *
 * Model version                  : 5.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri May 24 18:29:42 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller_arduino.h"

/* Model block global parameters (default storage) */
real_T rtP_MAX_TORQUE = 80.0;          /* Variable: MAX_TORQUE
                                        * Referenced by: '<Root>/Model'
                                        */
real_T rtP_MAX_TORQUE_REVERSE = 40.0;  /* Variable: MAX_TORQUE_REVERSE
                                        * Referenced by: '<Root>/Model'
                                        */

/* Block parameters (default storage) */
P_controller_arduino_T controller_arduino_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S3>/Constant'
   */
  30.0F,

  /* Mask Parameter: BitwiseAND_BitMask
   * Referenced by: '<Root>/Bitwise AND'
   */
  4,

  /* Mask Parameter: BitwiseAND1_BitMask
   * Referenced by: '<Root>/Bitwise AND1'
   */
  2,

  /* Mask Parameter: BitwiseAND2_BitMask
   * Referenced by: '<Root>/Bitwise AND2'
   */
  1,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input2'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Analog Input3'
   */
  -1.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Digital Input'
   */
  0.1,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain2'
   */
  0.0048875855327468231,

  /* Expression: 1/5
   * Referenced by: '<Root>/Gain5'
   */
  0.2,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain1'
   */
  0.0048875855327468231,

  /* Expression: 4/5
   * Referenced by: '<Root>/Gain4'
   */
  0.8,

  /* Expression: 5/(2^10-1)
   * Referenced by: '<Root>/Gain3'
   */
  0.0048875855327468231,

  /* Expression: 300/5
   * Referenced by: '<Root>/Gain'
   */
  60.0,

  /* Expression: 60
   * Referenced by: '<Root>/Constant'
   */
  60.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
