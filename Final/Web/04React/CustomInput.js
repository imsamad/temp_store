import React, { useState } from 'react';

const Form = () => {
  const input = '';

  const selects = [
    { value: 'sOne', label: 'Select One' },
    { value: 'sTwo', label: 'Select Two' },
    { value: 'sThree', label: 'Select Three' },
    { value: 'sFour', label: 'Select Four' },
    { value: 'sFive', label: 'Select Five' },
  ];
  const checks = [
    { value: 'cOne', label: 'Check One' },
    { value: 'cTwo', label: 'Check Two' },
    { value: 'cThree', label: 'Check Three' },
    { value: 'cFour', label: 'Check Four' },
    { value: 'cFive', label: 'Check Five' },
  ];
  const radios = [
    { value: 'rOne', label: 'Radio One' },
    { value: 'rTwo', label: 'Radio Two' },
    { value: 'rThree', label: 'Radio Three' },
    { value: 'rFour', label: 'Radio Four' },
    { value: 'rFive', label: 'Radio Five' },
  ];

  const [inputs, setInputs] = useState({
    select: selects[2].value,
    check: [checks[1].value],
    radio: radios[0].value,
    date: new Date().toISOString().split('T')[0],
  });
  // console.log('inputs', inputs);

  const handleChange = (e) => {
    let {
      target: { name, value, type },
    } = e;
    // console.log('value ', value);

    if (type == 'checkbox')
      if (inputs.check.includes(value))
        value = inputs.check.filter((val) => val != value);
      else value = [value, ...inputs.check];

    // console.log('e ', e.target?.type);
    // console.log('name ', name);
    // console.log('type ', type);

    setInputs((prev) => ({ ...prev, [name]: value }));
  };

  return (
    <div>
      <div>
        <h5>Select</h5>
        <select name="select" onChange={handleChange} value={inputs.select}>
          {selects.map((select) => (
            <option key={select.value} value={select.value}>
              {select.label}
            </option>
          ))}
        </select>
      </div>
      <div>
        <h5>Checkbox</h5>
        {checks.map((check) => (
          <React.Fragment key={check.value}>
            <input
              type="checkbox"
              name="check"
              value={check.value}
              id={check.value}
              onChange={handleChange}
              checked={inputs.check.includes(check.value)}
              style={{ margin: 5 }}
            />
            <label htmlFor={check.value}>{check.label}</label>
            <br />

            {/* <label>
              <input
                type="checkbox"
                name="check"
                value={check.value}
                onChange={handleChange}
                checked={inputs.check.includes(check.value)}
                style={{ margin: 5 }}
              />
              {check.label}
            </label>
            <br /> */}
          </React.Fragment>
        ))}
      </div>
      <div>
        <h5>Radios</h5>
        {radios.map((radio) => (
          <React.Fragment key={radio.value}>
            <input
              type="radio"
              name="radio"
              value={radio.value}
              id={radio.value}
              onChange={handleChange}
              checked={inputs.radio === radio.value}
              style={{ margin: 5 }}
            />
            <label htmlFor={radio.value}>{radio.label}</label>
            <br />

            {/* <label>
              <input
                type="radio"
                name="radio"
                value={radio.value}
                onChange={handleChange}
                checked={inputs.radio === radio.value}
                style={{ margin: 5 }}
              />
              {radio.label}
            </label>
            <br /> */}
          </React.Fragment>
        ))}
        <div>
          <h5>Date</h5>
          <input
            type="date"
            value={inputs.date}
            name="date"
            onChange={handleChange}
          />
        </div>
      </div>
    </div>
  );
};

export default Form;
