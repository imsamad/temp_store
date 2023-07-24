import axios from 'axios';
export const getUser = () =>
  axios.get('https://randomuser.me/api/?results=5').then(({ data }) => data);
