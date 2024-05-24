/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_arduino.h
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

#ifndef RTW_HEADER_controller_arduino_h_
#define RTW_HEADER_controller_arduino_h_
#ifndef controller_arduino_COMMON_INCLUDES_
#define controller_arduino_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* controller_arduino_COMMON_INCLUDES_ */

#include "controller_arduino_types.h"
#include "controller.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T Cast2;                      /* '<Root>/Cast2' */
  real32_T Cast;                       /* '<Root>/Cast' */
  real32_T TorqueRequest_Nm;           /* '<Root>/Model' */
  TransmissionState Cast1;             /* '<Root>/Cast1' */
  TransmissionState AutomaticTransmissionState;/* '<Root>/Model' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
} B_controller_arduino_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input3' */
  codertarget_arduinobase_inter_T obj_b;/* '<Root>/Analog Input2' */
  codertarget_arduinobase_inter_T obj_h;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_block_T obj_d;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_j_T obj_a;/* '<Root>/Digital Output4' */
  codertarget_arduinobase_blo_j_T obj_e;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_blo_j_T obj_f;/* '<Root>/Digital Output2' */
  codertarget_arduinobase_blo_j_T obj_j;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_blo_j_T obj_hy;/* '<Root>/Digital Output' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
  MdlrefDW_controller_T Model_InstanceData;/* '<Root>/Model' */
} DW_controller_arduino_T;

/* Parameters (default storage) */
struct P_controller_arduino_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S3>/Constant'
                                       */
  int8_T BitwiseAND_BitMask;           /* Mask Parameter: BitwiseAND_BitMask
                                        * Referenced by: '<Root>/Bitwise AND'
                                        */
  int8_T BitwiseAND1_BitMask;          /* Mask Parameter: BitwiseAND1_BitMask
                                        * Referenced by: '<Root>/Bitwise AND1'
                                        */
  int8_T BitwiseAND2_BitMask;          /* Mask Parameter: BitwiseAND2_BitMask
                                        * Referenced by: '<Root>/Bitwise AND2'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input2'
                                        */
  real_T AnalogInput3_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input3'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Gain2_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/5
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 4/5
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 5/(2^10-1)
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 300/5
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<Root>/Constant'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<Root>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_arduino_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_controller_arduino_T controller_arduino_P;

/* Block signals (default storage) */
extern B_controller_arduino_T controller_arduino_B;

/* Block states (default storage) */
extern DW_controller_arduino_T controller_arduino_DW;

/* Model block global parameters (default storage) */
extern real_T rtP_MAX_TORQUE;          /* Variable: MAX_TORQUE
                                        * Referenced by: '<Root>/Model'
                                        */
extern real_T rtP_MAX_TORQUE_REVERSE;  /* Variable: MAX_TORQUE_REVERSE
                                        * Referenced by: '<Root>/Model'
                                        */

/* External function called from main */
extern void controller_arduino_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void controller_arduino_initialize(void);
extern void controller_arduino_step0(void);
extern void controller_arduino_step1(void);
extern void controller_arduino_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controller_arduino_T *const controller_arduino_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller_arduino'
 * '<S1>'   : 'controller_arduino/Bit Shift'
 * '<S2>'   : 'controller_arduino/Bit Shift1'
 * '<S3>'   : 'controller_arduino/Compare To Constant'
 * '<S4>'   : 'controller_arduino/Bit Shift/bit_shift'
 * '<S5>'   : 'controller_arduino/Bit Shift1/bit_shift'
 */
#endif                                 /* RTW_HEADER_controller_arduino_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
