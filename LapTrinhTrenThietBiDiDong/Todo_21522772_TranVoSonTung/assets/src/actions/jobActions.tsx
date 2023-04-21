import Job from '../types/job';

export const SET_JOB = 'SET_JOB';
export const ADD_JOB = 'ADD_JOB';

export interface JobAction {
  type: string;
  payload: Job;
}

export const setJob = (job: Job): Object => {
  return {
    type: SET_JOB,
    payload: job,
  };
};

export const addJob = (job: Job): Object => {
  return {
    type: ADD_JOB,
    payload: job,
  };
};
