/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controller_arduino.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "controller_arduino_types.h"
#include "controller.h"

/* Block signals (default storage) */
B_controller_arduino_T controller_arduino_B;

/* Block states (default storage) */
DW_controller_arduino_T controller_arduino_DW;

/* Real-time model */
static RT_MODEL_controller_arduino_T controller_arduino_M_;
RT_MODEL_controller_arduino_T *const controller_arduino_M =
  &controller_arduino_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void controller_arduino_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(controller_arduino_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (controller_arduino_M->Timing.TaskCounters.TID[1])++;
  if ((controller_arduino_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.5s, 0.0s] */
    controller_arduino_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void controller_arduino_step0(void)    /* Sample time: [0.1s, 0.0s] */
{
  real_T tmp;
  uint16_T b_varargout_1;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  if (controller_arduino_DW.obj_d.SampleTime !=
      controller_arduino_P.DigitalInput_SampleTime) {
    controller_arduino_DW.obj_d.SampleTime =
      controller_arduino_P.DigitalInput_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  controller_arduino_B.DigitalInput = readDigitalPin(8);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (controller_arduino_DW.obj_h.SampleTime !=
      controller_arduino_P.AnalogInput1_SampleTime) {
    controller_arduino_DW.obj_h.SampleTime =
      controller_arduino_P.AnalogInput1_SampleTime;
  }

  controller_arduino_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (controller_arduino_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Cast2' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain5'
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  controller_arduino_B.Cast2 = (real32_T)(controller_arduino_P.Gain2_Gain *
    (real_T)b_varargout_1 * controller_arduino_P.Gain5_Gain);

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (controller_arduino_DW.obj_b.SampleTime !=
      controller_arduino_P.AnalogInput2_SampleTime) {
    controller_arduino_DW.obj_b.SampleTime =
      controller_arduino_P.AnalogInput2_SampleTime;
  }

  controller_arduino_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(16UL);
  MW_AnalogInSingle_ReadResult
    (controller_arduino_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Cast3' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Double2'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain4'
   *  MATLABSystem: '<Root>/Analog Input2'
   * */
  tmp = floor(controller_arduino_P.Gain1_Gain * (real_T)b_varargout_1 *
              controller_arduino_P.Gain4_Gain);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* DataTypeConversion: '<Root>/Cast1' incorporates:
   *  DataTypeConversion: '<Root>/Cast3'
   */
  controller_arduino_B.Cast1 = (TransmissionState)(int8_T)(tmp < 0.0 ? (int16_T)
    (int8_T)-(int8_T)(uint8_T)-tmp : (int16_T)(int8_T)(uint8_T)tmp);

  /* MATLABSystem: '<Root>/Analog Input3' */
  if (controller_arduino_DW.obj.SampleTime !=
      controller_arduino_P.AnalogInput3_SampleTime) {
    controller_arduino_DW.obj.SampleTime =
      controller_arduino_P.AnalogInput3_SampleTime;
  }

  controller_arduino_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(17UL);
  MW_AnalogInSingle_ReadResult
    (controller_arduino_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* DataTypeConversion: '<Root>/Cast' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Cast To Double3'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain3'
   *  MATLABSystem: '<Root>/Analog Input3'
   *  Sum: '<Root>/Add'
   * */
  controller_arduino_B.Cast = (real32_T)(controller_arduino_P.Gain3_Gain *
    (real_T)b_varargout_1 * controller_arduino_P.Gain_Gain -
    controller_arduino_P.Constant_Value);

  /* ModelReference: '<Root>/Model' */
  controller(&controller_arduino_B.DigitalInput, &controller_arduino_B.Cast2,
             &controller_arduino_B.Cast1, &controller_arduino_B.Cast,
             &controller_arduino_B.TorqueRequest_Nm,
             &controller_arduino_B.AutomaticTransmissionState,
             &(controller_arduino_DW.Model_InstanceData.rtdw));

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<S3>/Constant'
   *  RelationalOperator: '<S3>/Compare'
   */
  writeDigitalPin(2, (uint8_T)(controller_arduino_B.TorqueRequest_Nm >=
    controller_arduino_P.CompareToConstant_const));

  /* Outputs for Atomic SubSystem: '<Root>/Bit Shift' */
  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  DataTypeConversion: '<Root>/Cast4'
   *  MATLAB Function: '<S1>/bit_shift'
   *  S-Function (sfix_bitop): '<Root>/Bitwise AND'
   */
  writeDigitalPin(9, (uint8_T)((uint16_T)((int16_T)
    controller_arduino_B.AutomaticTransmissionState &
    controller_arduino_P.BitwiseAND_BitMask) >> 2));

  /* End of Outputs for SubSystem: '<Root>/Bit Shift' */

  /* Outputs for Atomic SubSystem: '<Root>/Bit Shift1' */
  /* MATLABSystem: '<Root>/Digital Output2' incorporates:
   *  DataTypeConversion: '<Root>/Cast4'
   *  MATLAB Function: '<S2>/bit_shift'
   *  S-Function (sfix_bitop): '<Root>/Bitwise AND1'
   */
  writeDigitalPin(10, (uint8_T)((uint16_T)((int16_T)
    controller_arduino_B.AutomaticTransmissionState &
    controller_arduino_P.BitwiseAND1_BitMask) >> 1));

  /* End of Outputs for SubSystem: '<Root>/Bit Shift1' */

  /* MATLABSystem: '<Root>/Digital Output4' incorporates:
   *  DataTypeConversion: '<Root>/Cast4'
   *  S-Function (sfix_bitop): '<Root>/Bitwise AND2'
   */
  writeDigitalPin(11, (uint8_T)((int16_T)
    controller_arduino_B.AutomaticTransmissionState &
    controller_arduino_P.BitwiseAND2_BitMask));
}

/* Model step function for TID1 */
void controller_arduino_step1(void)    /* Sample time: [0.5s, 0.0s] */
{
  /* Logic: '<Root>/NOT' incorporates:
   *  Delay: '<Root>/Delay'
   */
  controller_arduino_DW.Delay_DSTATE = !controller_arduino_DW.Delay_DSTATE;

  /* MATLABSystem: '<Root>/Digital Output3' incorporates:
   *  Delay: '<Root>/Delay'
   */
  writeDigitalPin(13, (uint8_T)controller_arduino_DW.Delay_DSTATE);
}

/* Model initialize function */
void controller_arduino_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  controller_initialize(rtmGetErrorStatusPointer(controller_arduino_M),
                        &(controller_arduino_DW.Model_InstanceData.rtm));

  /* InitializeConditions for Delay: '<Root>/Delay' */
  controller_arduino_DW.Delay_DSTATE =
    controller_arduino_P.Delay_InitialCondition;

  /* SystemInitialize for ModelReference: '<Root>/Model' */
  controller_Init(&(controller_arduino_DW.Model_InstanceData.rtdw));

  /* Start for MATLABSystem: '<Root>/Digital Input' */
  controller_arduino_DW.obj_d.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_d.SampleTime =
    controller_arduino_P.DigitalInput_SampleTime;
  controller_arduino_DW.obj_d.isInitialized = 1L;
  digitalIOSetup(8, 0);
  controller_arduino_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  controller_arduino_DW.obj_h.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_h.SampleTime =
    controller_arduino_P.AnalogInput1_SampleTime;
  controller_arduino_DW.obj_h.isInitialized = 1L;
  controller_arduino_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(15UL);
  controller_arduino_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input2' */
  controller_arduino_DW.obj_b.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_b.SampleTime =
    controller_arduino_P.AnalogInput2_SampleTime;
  controller_arduino_DW.obj_b.isInitialized = 1L;
  controller_arduino_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(16UL);
  controller_arduino_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input3' */
  controller_arduino_DW.obj.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj.SampleTime =
    controller_arduino_P.AnalogInput3_SampleTime;
  controller_arduino_DW.obj.isInitialized = 1L;
  controller_arduino_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(17UL);
  controller_arduino_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  controller_arduino_DW.obj_hy.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_hy.isInitialized = 1L;
  digitalIOSetup(2, 1);
  controller_arduino_DW.obj_hy.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  controller_arduino_DW.obj_j.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(9, 1);
  controller_arduino_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output2' */
  controller_arduino_DW.obj_f.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_f.isInitialized = 1L;
  digitalIOSetup(10, 1);
  controller_arduino_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output4' */
  controller_arduino_DW.obj_a.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_a.isInitialized = 1L;
  digitalIOSetup(11, 1);
  controller_arduino_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output3' */
  controller_arduino_DW.obj_e.matlabCodegenIsDeleted = false;
  controller_arduino_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(13, 1);
  controller_arduino_DW.obj_e.isSetupComplete = true;
}

/* Model terminate function */
void controller_arduino_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!controller_arduino_DW.obj_d.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!controller_arduino_DW.obj_h.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((controller_arduino_DW.obj_h.isInitialized == 1L) &&
        controller_arduino_DW.obj_h.isSetupComplete) {
      controller_arduino_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (controller_arduino_DW.obj_h.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input2' */
  if (!controller_arduino_DW.obj_b.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((controller_arduino_DW.obj_b.isInitialized == 1L) &&
        controller_arduino_DW.obj_b.isSetupComplete) {
      controller_arduino_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(16UL);
      MW_AnalogIn_Close
        (controller_arduino_DW.obj_b.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input2' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input3' */
  if (!controller_arduino_DW.obj.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_arduino_DW.obj.isInitialized == 1L) &&
        controller_arduino_DW.obj.isSetupComplete) {
      controller_arduino_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(17UL);
      MW_AnalogIn_Close
        (controller_arduino_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input3' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!controller_arduino_DW.obj_hy.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_hy.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!controller_arduino_DW.obj_j.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output2' */
  if (!controller_arduino_DW.obj_f.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output4' */
  if (!controller_arduino_DW.obj_a.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output4' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!controller_arduino_DW.obj_e.matlabCodegenIsDeleted) {
    controller_arduino_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
