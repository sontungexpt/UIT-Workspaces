import { SET_JOB, ADD_JOB, JobAction } from '../actions/jobActions';
import Job from '../types/job';

const initialState = {
  job: { title: '', description: '', date: new Date() } as Job,
  jobs: [] as Job[],
};

const jobReducer = (state = initialState, action: JobAction) => {
  switch (action.type) {
    case SET_JOB:
      return {
        ...state,
        job: action.payload,
      };
    case ADD_JOB:
      return {
        ...state,
        jobs: [...state.jobs, action.payload],
      };
    default:
      console.log('action not found');
      return state;
  }
};

export default jobReducer;
